#include "companies_index.h"
#include "map.h"

#include <algorithm>
#include <iterator>
#include <optional>

using namespace std;

namespace YellowPages {

  void CompaniesIndex::UpdateNameIndex(const Company& company) {
    for (const auto& name : company.names()) {
      name_index_[name.value()].push_back(&company);
    }
  }

  void CompaniesIndex::UpdateUrlIndex(const Company& company) {
    for (const auto& url : company.urls()) {
      url_index_[url.value()].push_back(&company);
    }
  }

  void CompaniesIndex::UpdateRubricIndex(const Company& company) {
    for (const uint64_t rubric : company.rubrics()) {
      rubric_index_[rubric].push_back(&company);
    }
  }

  void CompaniesIndex::UpdatePhoneIndex(const Company& company) {
    for (const Phone& phone : company.phones()) {
      for (int has_ext_mode = phone.extension().empty(); has_ext_mode <= 1; ++has_ext_mode) {
        for (int codes_mode = 0; codes_mode <= 2; ++codes_mode) {
          Phone phone_copy = phone;
          if (!has_ext_mode) {
            phone_copy.clear_extension();
          }
          if (codes_mode <= 1) {
            phone_copy.clear_country_code();
          }
          if (codes_mode == 0) {
            phone_copy.clear_local_code();
          }
          for (const bool has_type : {true, false}) {
            if (!has_type) {
              phone_copy.clear_type();
            }
            phone_index_[{phone_copy, has_type}].push_back(&company);
          }
        }
      }
    }
  }

  template <typename Map>
  static void SortValues(Map& map) {
    for (auto& [key, value] : map) {
      sort(begin(value), end(value));
    }
  }

  void CompaniesIndex::SortCompanies() {
    SortValues(name_index_);
    SortValues(url_index_);
    SortValues(rubric_index_);
    SortValues(phone_index_);
  }

  struct Identity {
    template<typename Value>
    decltype(auto) operator()(Value&& value) const {
      return forward<Value>(value);
    }
  };

  template<typename Index, typename ValuesIt, typename ValueProj = Identity>
  static optional<Companies> MergeCompanies(
      const Index& index,
      ValuesIt values_begin, ValuesIt values_end,
      ValueProj value_proj = {}
  ) {
    if (values_begin == values_end) {
      return nullopt;
    }
    Companies companies_list;
    for (const auto& value : Range(values_begin, values_end)) {
      const Companies* const new_companies = GetValuePointer(index, value_proj(value));
      if (!new_companies) {
        continue;
      }
      Companies united;
      united.reserve(companies_list.size() + new_companies->size());
      set_union(
          begin(companies_list), end(companies_list),
          begin(*new_companies), end(*new_companies),
          back_inserter(united)
      );
      united.erase(unique(begin(united), end(united)), end(united));
      companies_list = move(united);
    }
    return move(companies_list);
  }

  Companies CompaniesIndex::Find(const CompanyQuery& query, const RubricsNameToId& rubrics_name_to_id) const {
    vector<Companies> companies_lists;

#define \
    PROCESS_KEY_PROJ(key, proj) \
      if (auto companies_opt = MergeCompanies(key##_index_, begin(query.key##s), end(query.key##s), proj)) { \
        if (companies_opt->empty()) { \
          return {}; \
        } \
        companies_lists.push_back(move(*companies_opt)); \
      }

#define \
    PROCESS_KEY(key) PROCESS_KEY_PROJ(key, Identity{})

    PROCESS_KEY(name);
    PROCESS_KEY(url);
    PROCESS_KEY_PROJ(rubric, [&rubrics_name_to_id](const string& rubric_name) { return rubrics_name_to_id.at(rubric_name); });
    PROCESS_KEY(phone);

    // at least one filter is required
    assert(!companies_lists.empty());

    if (companies_lists.size() == 1) {
      return companies_lists[0];
    }

    Companies companies;
    set_intersection(
        begin(companies_lists[0]), end(companies_lists[0]),
        begin(companies_lists[1]), end(companies_lists[1]),
        back_inserter(companies)
    );

    for (size_t companies_idx = 2; companies_idx < companies_lists.size(); ++companies_idx) {
      const Companies& companies_part = companies_lists[companies_idx];
      companies.erase(
          set_intersection(
              begin(companies), end(companies),
              begin(companies_part), end(companies_part),
              begin(companies)
          ),
          end(companies)
      );
    }

    return companies;
  }

}
