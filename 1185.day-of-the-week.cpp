/*
 * @lc app=leetcode id=1185 lang=cpp
 *
 * [1185] Day of the Week
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string dayOfTheWeek(int day, int month, int year) {
    const std::string day_of_the_week[] = {"Sunday",    "Monday",   "Tuesday",
                                           "Wednesday", "Thursday", "Friday",
                                           "Saturday"};
    constexpr int day_of_month[] = {
        0,
        31,
        31 + 28,
        31 + 28 + 31,
        31 + 28 + 31 + 30,
        31 + 28 + 31 + 30 + 31,
        31 + 28 + 31 + 30 + 31 + 30,
        31 + 28 + 31 + 30 + 31 + 30 + 31,
        31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
        31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
        31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
        31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
        31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31};
    int offset = 5;
    offset += day - 1;
    offset += day_of_month[month - 1] % 7;
    if (is_leap_year(year) && month > 2) {
      offset++;
    }
    for (int i = 1971; i < year; i++) {
      if (is_leap_year(i)) {
        offset += 2;
      } else {
        offset++;
      }
    }
    return day_of_the_week[offset % 7];
  }

 private:
  bool is_leap_year(int year) {
    return (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0));
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.dayOfTheWeek(1, 1, 1971), "Friday");
  ASSERT_EQ(s.dayOfTheWeek(2, 1, 1971), "Saturday");
  ASSERT_EQ(s.dayOfTheWeek(3, 1, 1971), "Sunday");
  ASSERT_EQ(s.dayOfTheWeek(1, 2, 1971), "Monday");
  ASSERT_EQ(s.dayOfTheWeek(1, 1, 1972), "Saturday");
  ASSERT_EQ(s.dayOfTheWeek(1, 1, 1973), "Monday");
  ASSERT_EQ(s.dayOfTheWeek(31, 8, 2019), "Saturday");
  ASSERT_EQ(s.dayOfTheWeek(18, 7, 1999), "Sunday");
  ASSERT_EQ(s.dayOfTheWeek(15, 8, 1993), "Sunday");
  ASSERT_EQ(s.dayOfTheWeek(31, 8, 2100), "Tuesday");
  return 0;
}
