/*
 * @lc app=leetcode id=1260 lang=cpp
 *
 * [1260] Shift 2D Grid
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    int num = m * n;
    k = k % num;
    auto ret = grid;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int new_j = (j + k) % n;
        int new_i = (i + (j + k) / n) % m;
        ret[new_i][new_j] = grid[i][j];
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> grid, exp;

  grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  exp = {{9, 1, 2}, {3, 4, 5}, {6, 7, 8}};
  ASSERT_EQ(s.shiftGrid(grid, 1), exp);

  grid = {{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}};
  exp = {{12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}};
  ASSERT_EQ(s.shiftGrid(grid, 4), exp);

  grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  exp = grid;
  ASSERT_EQ(s.shiftGrid(grid, 9), exp);

  grid = {{1}, {2}, {3}, {4}, {7}, {6}, {5}};
  exp = {{6}, {5}, {1}, {2}, {3}, {4}, {7}};
  ASSERT_EQ(s.shiftGrid(grid, 23), exp);
  return 0;
}
