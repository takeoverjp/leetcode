/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int ret = 0;
    int row = grid.size();
    int col = grid[0].size();
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j]) {
          if ((j == 0) || (!grid[i][j - 1])) ret++;
          if ((j == col - 1) || (!grid[i][j + 1])) ret++;
          if ((i == 0) || (!grid[i - 1][j])) ret++;
          if ((i == row - 1) || (!grid[i + 1][j])) ret++;
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> grid;
  grid = {{1}};
  assert(s.islandPerimeter(grid) == 4);
  grid = {{1, 0}};
  assert(s.islandPerimeter(grid) == 4);
  grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  assert(s.islandPerimeter(grid) == 16);
  return 0;
}
