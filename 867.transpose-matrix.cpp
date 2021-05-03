/*
 * @lc app=leetcode id=867 lang=cpp
 *
 * [867] Transpose Matrix
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    vector<vector<int>> ret;
    int width = matrix[0].size();
    int height = matrix.size();
    ret.resize(width);
    for (int x = 0; x < width; x++) {
      ret[x].resize(height);
      for (int y = 0; y < height; y++) {
        ret[x][y] = matrix[y][x];
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> matrix, exp;

  matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  exp = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
  assert(s.transpose(matrix) == exp);

  matrix = {{1, 2, 3}, {4, 5, 6}};
  exp = {{1, 4}, {2, 5}, {3, 6}};
  assert(s.transpose(matrix) == exp);
  return 0;
}
