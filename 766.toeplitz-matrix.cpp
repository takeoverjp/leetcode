/*
 * @lc app=leetcode id=766 lang=cpp
 *
 * [766] Toeplitz Matrix
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int h = matrix.size();
    if (h <= 1) {
      return true;
    }
    int w = matrix[0].size();
    if (w <= 1) {
      return true;
    }
    for (int diff = -(h - 1); diff <= w - 1; diff++) {
      int val = -1;
      for (int x = 0; x < w; x++) {
        int y = x - diff;
        if (y < 0 || y >= h) {
          continue;
        }
        if (val < 0) {
          val = matrix[y][x];
        } else {
          if (val != matrix[y][x]) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> matrix;
  matrix = {{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}};
  ASSERT_EQ(s.isToeplitzMatrix(matrix), true);
  matrix = {{1, 2}, {2, 2}};
  ASSERT_EQ(s.isToeplitzMatrix(matrix), false);
  matrix = {{1, 2, 3}};
  ASSERT_EQ(s.isToeplitzMatrix(matrix), true);
  matrix = {{1}, {2}, {3}};
  ASSERT_EQ(s.isToeplitzMatrix(matrix), true);
  return 0;
}
