/*
 * @lc app=leetcode id=1360 lang=cpp
 *
 * [1360] Number of Days Between Two Dates
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int daysBetweenDates(string date1, string date2) {
    auto t1 = parse(date1);
    auto t2 = parse(date2);
    return std::abs(t1 - t2);
  }

 private:
  int parse(std::string& date) {
    std::stringstream ss{date};
    int year, month, day;
    ss >> year;
    ss.ignore();
    ss >> month;
    ss.ignore();
    ss >> day;

    struct tm t {
      0, 0, 0, day, month - 1, year - 1900, 0, 0, 0, 0, 0
    };

    return std::mktime(&t) / 24 / 3600;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.daysBetweenDates("2019-06-29", "2019-06-30"), 1);
  ASSERT_EQ(s.daysBetweenDates("2020-01-15", "2019-12-31"), 15);
  ASSERT_EQ(s.daysBetweenDates("1971-06-29", "2010-09-23"), 14331);
  ASSERT_EQ(s.daysBetweenDates("2074-09-12", "1983-01-08"), 33485);
  return 0;
}
