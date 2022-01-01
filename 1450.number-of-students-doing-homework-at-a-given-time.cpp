/*
 * @lc app=leetcode id=1450 lang=cpp
 *
 * [1450] Number of Students Doing Homework at a Given Time
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
    int size = startTime.size();
    int ret = 0;
    for (int i = 0; i < size; i++) {
      if (startTime[i] <= queryTime && queryTime <= endTime[i]) {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> startTime, endTime;
  startTime = {1, 2, 3};
  endTime = {3, 2, 7};
  ASSERT_EQ(s.busyStudent(startTime, endTime, 4), 1);
  startTime = {4};
  endTime = {4};
  ASSERT_EQ(s.busyStudent(startTime, endTime, 4), 1);
  return 0;
}
