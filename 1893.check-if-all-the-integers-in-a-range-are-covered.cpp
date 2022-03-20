/*
 * @lc app=leetcode id=1893 lang=cpp
 *
 * [1893] Check if All the Integers in a Range Are Covered
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isCovered(vector<vector<int>>& ranges, int left, int right) {
    bool covered[50];
    memset(covered, 0, sizeof(covered));
    for (const auto& range : ranges) {
      for (int num = range[0]; num <= range[1]; num++) {
        covered[num - 1] = true;
      }
    }
    for (int num = left; num <= right; num++) {
      if (!covered[num - 1]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> ranges;
  ranges = {{1, 2}, {3, 4}, {5, 6}};
  ASSERT_EQ(s.isCovered(ranges, 2, 5), true);
  ranges = {{1, 10}, {10, 20}};
  ASSERT_EQ(s.isCovered(ranges, 21, 21), false);
  ranges = {{1, 50}};
  ASSERT_EQ(s.isCovered(ranges, 1, 50), true);
  return 0;
}
