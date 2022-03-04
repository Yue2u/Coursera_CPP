#pragma once

#include "working_time.pb.h"
#include <utility>

namespace YellowPages {

  void ValidateWorkingTime(const WorkingTime& wt);

  std::pair<int, int> ToWeekMinutesInterval(const WorkingTimeInterval& interval);

  double ComputeMinutesToNearestInterval(double week_minutes, const WorkingTime& working_time);

}
