// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: database.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_database_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_database_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3017000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3017003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/map.h>  // IWYU pragma: export
#include <google/protobuf/map_entry.h>
#include <google/protobuf/map_field_inl.h>
#include <google/protobuf/unknown_field_set.h>
#include "company.pb.h"
#include "rubric.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_database_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_database_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_database_2eproto;
namespace YellowPages {
class Database;
struct DatabaseDefaultTypeInternal;
extern DatabaseDefaultTypeInternal _Database_default_instance_;
class Database_RubricsEntry_DoNotUse;
struct Database_RubricsEntry_DoNotUseDefaultTypeInternal;
extern Database_RubricsEntry_DoNotUseDefaultTypeInternal _Database_RubricsEntry_DoNotUse_default_instance_;
}  // namespace YellowPages
PROTOBUF_NAMESPACE_OPEN
template<> ::YellowPages::Database* Arena::CreateMaybeMessage<::YellowPages::Database>(Arena*);
template<> ::YellowPages::Database_RubricsEntry_DoNotUse* Arena::CreateMaybeMessage<::YellowPages::Database_RubricsEntry_DoNotUse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace YellowPages {

// ===================================================================

class Database_RubricsEntry_DoNotUse : public ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Database_RubricsEntry_DoNotUse, 
    ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_UINT64,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> {
public:
  typedef ::PROTOBUF_NAMESPACE_ID::internal::MapEntry<Database_RubricsEntry_DoNotUse, 
    ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_UINT64,
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> SuperType;
  Database_RubricsEntry_DoNotUse();
  explicit constexpr Database_RubricsEntry_DoNotUse(
      ::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);
  explicit Database_RubricsEntry_DoNotUse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  void MergeFrom(const Database_RubricsEntry_DoNotUse& other);
  static const Database_RubricsEntry_DoNotUse* internal_default_instance() { return reinterpret_cast<const Database_RubricsEntry_DoNotUse*>(&_Database_RubricsEntry_DoNotUse_default_instance_); }
  static bool ValidateKey(void*) { return true; }
  static bool ValidateValue(void*) { return true; }
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
};

// -------------------------------------------------------------------

class Database final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:YellowPages.Database) */ {
 public:
  inline Database() : Database(nullptr) {}
  ~Database() override;
  explicit constexpr Database(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  Database(const Database& from);
  Database(Database&& from) noexcept
    : Database() {
    *this = ::std::move(from);
  }

  inline Database& operator=(const Database& from) {
    CopyFrom(from);
    return *this;
  }
  inline Database& operator=(Database&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const Database& default_instance() {
    return *internal_default_instance();
  }
  static inline const Database* internal_default_instance() {
    return reinterpret_cast<const Database*>(
               &_Database_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(Database& a, Database& b) {
    a.Swap(&b);
  }
  inline void Swap(Database* other) {
    if (other == this) return;
    if (GetOwningArena() == other->GetOwningArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Database* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Database* New() const final {
    return new Database();
  }

  Database* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Database>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const Database& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const Database& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message*to, const ::PROTOBUF_NAMESPACE_ID::Message&from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Database* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "YellowPages.Database";
  }
  protected:
  explicit Database(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------


  // accessors -------------------------------------------------------

  enum : int {
    kCompaniesFieldNumber = 1,
    kRubricsFieldNumber = 2,
  };
  // repeated .YellowPages.Company companies = 1;
  int companies_size() const;
  private:
  int _internal_companies_size() const;
  public:
  void clear_companies();
  ::YellowPages::Company* mutable_companies(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Company >*
      mutable_companies();
  private:
  const ::YellowPages::Company& _internal_companies(int index) const;
  ::YellowPages::Company* _internal_add_companies();
  public:
  const ::YellowPages::Company& companies(int index) const;
  ::YellowPages::Company* add_companies();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Company >&
      companies() const;

  // map<uint64, .YellowPages.Rubric> rubrics = 2;
  int rubrics_size() const;
  private:
  int _internal_rubrics_size() const;
  public:
  void clear_rubrics();
  private:
  const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >&
      _internal_rubrics() const;
  ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >*
      _internal_mutable_rubrics();
  public:
  const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >&
      rubrics() const;
  ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >*
      mutable_rubrics();

  // @@protoc_insertion_point(class_scope:YellowPages.Database)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Company > companies_;
  ::PROTOBUF_NAMESPACE_ID::internal::MapField<
      Database_RubricsEntry_DoNotUse,
      ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_UINT64,
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_MESSAGE> rubrics_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_database_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// Database

// repeated .YellowPages.Company companies = 1;
inline int Database::_internal_companies_size() const {
  return companies_.size();
}
inline int Database::companies_size() const {
  return _internal_companies_size();
}
inline ::YellowPages::Company* Database::mutable_companies(int index) {
  // @@protoc_insertion_point(field_mutable:YellowPages.Database.companies)
  return companies_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Company >*
Database::mutable_companies() {
  // @@protoc_insertion_point(field_mutable_list:YellowPages.Database.companies)
  return &companies_;
}
inline const ::YellowPages::Company& Database::_internal_companies(int index) const {
  return companies_.Get(index);
}
inline const ::YellowPages::Company& Database::companies(int index) const {
  // @@protoc_insertion_point(field_get:YellowPages.Database.companies)
  return _internal_companies(index);
}
inline ::YellowPages::Company* Database::_internal_add_companies() {
  return companies_.Add();
}
inline ::YellowPages::Company* Database::add_companies() {
  ::YellowPages::Company* _add = _internal_add_companies();
  // @@protoc_insertion_point(field_add:YellowPages.Database.companies)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::YellowPages::Company >&
Database::companies() const {
  // @@protoc_insertion_point(field_list:YellowPages.Database.companies)
  return companies_;
}

// map<uint64, .YellowPages.Rubric> rubrics = 2;
inline int Database::_internal_rubrics_size() const {
  return rubrics_.size();
}
inline int Database::rubrics_size() const {
  return _internal_rubrics_size();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >&
Database::_internal_rubrics() const {
  return rubrics_.GetMap();
}
inline const ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >&
Database::rubrics() const {
  // @@protoc_insertion_point(field_map:YellowPages.Database.rubrics)
  return _internal_rubrics();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >*
Database::_internal_mutable_rubrics() {
  return rubrics_.MutableMap();
}
inline ::PROTOBUF_NAMESPACE_ID::Map< ::PROTOBUF_NAMESPACE_ID::uint64, ::YellowPages::Rubric >*
Database::mutable_rubrics() {
  // @@protoc_insertion_point(field_mutable_map:YellowPages.Database.rubrics)
  return _internal_mutable_rubrics();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace YellowPages

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_database_2eproto
