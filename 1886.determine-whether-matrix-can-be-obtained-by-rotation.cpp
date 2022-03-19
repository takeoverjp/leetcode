/*
 * @lc app=leetcode id=1886 lang=cpp
 *
 * [1886] Determine Whether Matrix Can Be Obtained By Rotation
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    int n = mat.size();
    if (mat == target) {
      return true;
    }
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (mat[y][x] != target[x][n - y - 1]) {
          goto NEXT_180;
        }
      }
    }
    return true;
  NEXT_180:
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (mat[y][x] != target[n - y - 1][n - x - 1]) {
          goto NEXT_270;
        }
      }
    }
    return true;
  NEXT_270:
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < n; y++) {
        if (mat[y][x] != target[n - x - 1][y]) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> mat;
  vector<vector<int>> target;
  mat = {{0, 1}, {1, 0}};
  target = {{1, 0}, {0, 1}};
  ASSERT_EQ(s.findRotation(mat, target), true);
  mat = {{0, 1}, {1, 1}};
  target = {{1, 0}, {0, 1}};
  ASSERT_EQ(s.findRotation(mat, target), false);
  mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
  target = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
  ASSERT_EQ(s.findRotation(mat, target), true);
  return 0;
}
