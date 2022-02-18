/*
 * @lc app=leetcode id=1736 lang=cpp
 *
 * [1736] Latest Time by Replacing Hidden Digits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string maximumTime(string time) {
    if (time[0] == '?') {
      if (time[1] == '?') {
        time[0] = '2';
        time[1] = '3';
      } else if (time[1] <= '3') {
        time[0] = '2';
      } else {
        time[0] = '1';
      }
    } else if (time[1] == '?') {
      if (time[0] == '2') {
        time[1] = '3';
      } else {
        time[1] = '9';
      }
    }
    if (time[3] == '?') {
      time[3] = '5';
    }
    if (time[4] == '?') {
      time[4] = '9';
    }
    return time;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.maximumTime("2?:?0"), "23:50");
  ASSERT_EQ(s.maximumTime("0?:3?"), "09:39");
  ASSERT_EQ(s.maximumTime("1?:22"), "19:22");
  return 0;
}
