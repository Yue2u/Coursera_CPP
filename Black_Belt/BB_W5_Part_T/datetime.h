#pragma once

constexpr int DAYS_IN_WEEK = 7;
constexpr int HOURS_IN_DAY = 24;
constexpr int MINUTES_IN_HOUR = 60;
constexpr int MINUTES_IN_WEEK = MINUTES_IN_HOUR * HOURS_IN_DAY * DAYS_IN_WEEK;

struct WeekDayTime {
  int weekday;
  int hours;
  int minutes;
};

int ToWeekMinutes(const WeekDayTime& time);
