/*
 * @lc app=leetcode id=1351 lang=cpp
 *
 * [1351] Count Negative Numbers in a Sorted Matrix
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countNegatives(vector<vector<int>>& grid) {
    int ret = 0;
    for (const auto& row : grid) {
      for (auto it = row.rbegin(); it != row.rend(); it++) {
        if (*it >= 0) {
          break;
        }
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> grid;
  grid = {{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}};
  ASSERT_EQ(s.countNegatives(grid), 8);
  grid = {{3, 2}, {1, 0}};
  ASSERT_EQ(s.countNegatives(grid), 0);
  grid = {{1, -1}, {-1, -1}};
  ASSERT_EQ(s.countNegatives(grid), 3);
  grid = {{-1}};
  ASSERT_EQ(s.countNegatives(grid), 1);
  return 0;
}
