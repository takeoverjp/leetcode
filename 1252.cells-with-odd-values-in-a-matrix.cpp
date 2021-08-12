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
    bool is_odd_row[m];
    bool is_odd_col[n];
    memset(is_odd_row, 0, sizeof(is_odd_row));
    memset(is_odd_col, 0, sizeof(is_odd_col));
    for (const auto& index : indices) {
      is_odd_row[index[0]] = !is_odd_row[index[0]];
      is_odd_col[index[1]] = !is_odd_col[index[1]];
    }

    int odd_row = 0;
    for (int i = 0; i < m; i++) {
      if (is_odd_row[i]) {
        odd_row++;
      }
    }
    int odd_col = 0;
    for (int i = 0; i < n; i++) {
      if (is_odd_col[i]) {
        odd_col++;
      }
    }
    return odd_row * n + odd_col * m - 2 * odd_row * odd_col;
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
