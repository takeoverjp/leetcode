/*
 * @lc app=leetcode id=1507 lang=cpp
 *
 * [1507] Reformat Date
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string reformatDate(string date) {
    int day;
    string garbage;
    string month;
    string year;
    stringstream datestream(date);
    datestream >> day >> garbage >> month >> year;
    int int_month = 1;
    const string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun",
                               "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    for (int i = 0; i < 12; i++) {
      if (months[i] == month) {
        int_month = i + 1;
      }
    }
    stringstream ret;
    ret << year << "-" << setfill('0') << setw(2) << int_month << "-"
        << setfill('0') << setw(2) << day;
    return ret.str();
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.reformatDate("20th Oct 2052"), "2052-10-20");
  ASSERT_EQ(s.reformatDate("6th Jun 1933"), "1933-06-06");
  ASSERT_EQ(s.reformatDate("26th May 1960"), "1960-05-26");
  return 0;
}
