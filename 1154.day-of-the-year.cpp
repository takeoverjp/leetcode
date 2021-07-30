/*
 * @lc app=leetcode id=1154 lang=cpp
 *
 * [1154] Day of the Year
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int dayOfYear(string date) {
    int year, month, day;
    sscanf(date.c_str(), "%04d-%02d-%02d", &year, &month, &day);
    const int leap_days[12] = {0,   31,  60,  91,  121, 152,
                               182, 213, 244, 274, 305, 335};
    const int normal_days[12] = {0,   31,  59,  90,  120, 151,
                                 181, 212, 243, 273, 304, 334};

    if (year % 4) {
      return normal_days[month - 1] + day;
    } else {
      return leap_days[month - 1] + day;
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.dayOfYear("2019-01-09"), 9);
  ASSERT_EQ(s.dayOfYear("2019-02-10"), 41);
  ASSERT_EQ(s.dayOfYear("2003-03-01"), 60);
  ASSERT_EQ(s.dayOfYear("2004-03-01"), 61);
  ASSERT_EQ(s.dayOfYear("2000-03-01"), 61);
  ASSERT_EQ(s.dayOfYear("2000-12-04"), 339);
  return 0;
}
