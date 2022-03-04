#include "datetime.h"

int ToWeekMinutes(const WeekDayTime& time) {
  return (time.weekday * HOURS_IN_DAY + time.hours) * MINUTES_IN_HOUR + time.minutes;
}
