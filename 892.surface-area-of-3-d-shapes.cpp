/*
 * @lc app=leetcode id=892 lang=cpp
 *
 * [892] Surface Area of 3D Shapes
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    return calcXY(grid) + calcYZ(grid) + calcZX(grid);
  }

 private:
  int calcXY(vector<vector<int>>& grid) {
    int ret = 0;
    for (auto& row : grid) {
      for (auto v : row) {
        if (v) ret++;
      }
    }
    return ret * 2;
  }
  int calcYZ(vector<vector<int>>& grid) {
    int ret = 0;
    int size = grid.size();
    for (int y = 0; y < size; y++) {
      ret += grid[y][0] + grid[y][size - 1];
      for (int x = 1; x < size; x++) {
        ret += abs(grid[y][x] - grid[y][x - 1]);
      }
    }
    return ret;
  }
  int calcZX(vector<vector<int>>& grid) {
    int ret = 0;
    int size = grid.size();
    for (int x = 0; x < size; x++) {
      ret += grid[0][x] + grid[size - 1][x];
      for (int y = 1; y < size; y++) {
        ret += abs(grid[y][x] - grid[y - 1][x]);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> grid;

  // Example 1
  grid = {{2}};
  ASSERT_EQ(s.surfaceArea(grid), 10);

  // Example 2
  grid = {{1, 2}, {3, 4}};
  ASSERT_EQ(s.surfaceArea(grid), 34);

  // Example 3
  grid = {{1, 0}, {0, 2}};
  ASSERT_EQ(s.surfaceArea(grid), 16);

  // Example 4
  grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  ASSERT_EQ(s.surfaceArea(grid), 32);

  // Example 5
  grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  ASSERT_EQ(s.surfaceArea(grid), 46);
  return 0;
}
