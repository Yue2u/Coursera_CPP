#include "working_time.h"
#include "datetime.h"
#include "numeric.h"
#include <tuple>

using namespace std;

namespace YellowPages {

  static constexpr int MINUTES_IN_DAY = MINUTES_IN_HOUR * HOURS_IN_DAY;

  static void ValidateInterval(const WorkingTimeInterval& interval) {
    const auto minutes_from = interval.minutes_from();
    const auto minutes_to = interval.minutes_to();
    assert(0 <= minutes_from);
    assert(minutes_from < minutes_to);
    assert(minutes_to <= MINUTES_IN_DAY);
  }

  void ValidateWorkingTime(const WorkingTime& wt) {
    if (wt.intervals_size() == 0) {
      return;
    }
    for (const auto& interval : wt.intervals()) {
      ValidateInterval(interval);
    }
    if (wt.intervals(0).day() == WorkingTimeInterval_Day_EVERYDAY) {
      for (const auto& interval : wt.intervals()) {
        assert(interval.day() == WorkingTimeInterval_Day_EVERYDAY);
      }
      return;
    }
    assert(wt.intervals(0).day() != WorkingTimeInterval_Day_EVERYDAY);
    for (int idx = 1; idx < wt.intervals_size(); ++idx) {
      assert(wt.intervals(idx).day() != WorkingTimeInterval_Day_EVERYDAY);
      const auto& interval_prev = wt.intervals(idx - 1);
      const auto& interval_next = wt.intervals(idx);
      assert(
          make_tuple(interval_prev.day(), interval_prev.minutes_to())
          < make_tuple(interval_next.day(), interval_next.minutes_from())
      );
    }
  }

  pair<int, int> ToWeekMinutesInterval(const WorkingTimeInterval& interval) {
    const int minutes_from_week_start =
        interval.day() == WorkingTimeInterval_Day_EVERYDAY
        ? 0
        : (interval.day() - 1) * MINUTES_IN_DAY;
    return {
        minutes_from_week_start + interval.minutes_from(),
        minutes_from_week_start + interval.minutes_to(),
    };
  }

  double ComputeMinutesToNearestInterval(double week_minutes, const WorkingTime& working_time) {
    if (working_time.intervals_size() == 0) {
      return 0;
    }
    const int modulo =
        (working_time.intervals(0).day() == WorkingTimeInterval_Day_EVERYDAY)
        ? MINUTES_IN_DAY
        : MINUTES_IN_WEEK;

    week_minutes = Modulo(week_minutes, modulo);

    auto nearest_it = upper_bound(
        begin(working_time.intervals()), end(working_time.intervals()),
        week_minutes,
        [](double week_minutes, const WorkingTimeInterval& interval) {
          return Less(week_minutes, ToWeekMinutesInterval(interval).second);
        }
    );
    if (nearest_it == end(working_time.intervals())) {
      nearest_it = begin(working_time.intervals());
    }
    const auto [nearest_from, nearest_to] = ToWeekMinutesInterval(*nearest_it);
    if (LessOrEqual(nearest_from, week_minutes) && Less(week_minutes, nearest_to)) {
      return 0;
    } else {
      return Modulo(nearest_from - week_minutes, modulo);
    }
  }

}
