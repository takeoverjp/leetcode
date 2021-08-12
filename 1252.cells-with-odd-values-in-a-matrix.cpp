/*
 * @lc app=leetcode id=1252 lang=cpp
 *
 * [1252] Cells with Odd Values in a Matrix
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int oddCells(int m, int n, vector<vector<int>>& indices) {
    bool is_odd[m][n];
    memset(is_odd, 0, sizeof(is_odd));
    for (const auto& index : indices) {
      for (int x = 0; x < n; x++) {
        is_odd[index[0]][x] = !is_odd[index[0]][x];
      }
      for (int y = 0; y < m; y++) {
        is_odd[y][index[1]] = !is_odd[y][index[1]];
      }
    }
    int ret = 0;
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        if (is_odd[y][x]) {
          ret++;
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> indices;
  indices = {{1, 1}, {0, 0}};
  ASSERT_EQ(s.oddCells(2, 2, indices), 0);
  indices = {{0, 1}, {1, 1}};
  ASSERT_EQ(s.oddCells(2, 3, indices), 6);
  return 0;
}
