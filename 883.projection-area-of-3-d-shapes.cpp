/*
 * @lc app=leetcode id=883 lang=cpp
 *
 * [883] Projection Area of 3D Shapes
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int projectionArea(vector<vector<int>>& grid) {
    return calcXY(grid) + calcXZ(grid) + calcYZ(grid);
  }

  int calcXY(vector<vector<int>>& grid) {
    int size = grid.size();
    int ret = 0;
    for (int y = 0; y < size; y++) {
      for (int x = 0; x < size; x++) {
        if (grid[y][x]) {
          ++ret;
        }
      }
    }
    return ret;
  }

  int calcXZ(vector<vector<int>>& grid) {
    int size = grid.size();
    int ret = 0;
    for (int x = 0; x < size; x++) {
      int max = 0;
      for (int y = 0; y < size; y++) {
        max = std::max(max, grid[y][x]);
      }
      ret += max;
    }
    return ret;
  }

  int calcYZ(vector<vector<int>>& grid) {
    int size = grid.size();
    int ret = 0;
    for (int y = 0; y < size; y++) {
      int max = 0;
      for (int x = 0; x < size; x++) {
        max = std::max(max, grid[y][x]);
      }
      ret += max;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> grid;

  // Example 1
  grid = {{1, 2}, {3, 4}};
  ASSERT_EQ(s.calcXY(grid), 4);
  ASSERT_EQ(s.calcXZ(grid), 7);
  ASSERT_EQ(s.calcYZ(grid), 6);
  ASSERT_EQ(s.projectionArea(grid), 17);

  // Example 2
  grid = {{2}};
  ASSERT_EQ(s.calcXY(grid), 1);
  ASSERT_EQ(s.calcXZ(grid), 2);
  ASSERT_EQ(s.calcYZ(grid), 2);
  ASSERT_EQ(s.projectionArea(grid), 5);

  // Example 3
  grid = {{1, 0}, {0, 2}};
  ASSERT_EQ(s.calcXY(grid), 2);
  ASSERT_EQ(s.calcXZ(grid), 3);
  ASSERT_EQ(s.calcYZ(grid), 3);
  ASSERT_EQ(s.projectionArea(grid), 8);

  // Example 4
  grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  ASSERT_EQ(s.calcXY(grid), 8);
  ASSERT_EQ(s.calcXZ(grid), 3);
  ASSERT_EQ(s.calcYZ(grid), 3);
  ASSERT_EQ(s.projectionArea(grid), 14);

  // Example 5
  grid = {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}};
  ASSERT_EQ(s.calcXY(grid), 9);
  ASSERT_EQ(s.calcXZ(grid), 6);
  ASSERT_EQ(s.calcYZ(grid), 6);
  ASSERT_EQ(s.projectionArea(grid), 21);
  return 0;
}
