/*
 * @lc app=leetcode id=1380 lang=cpp
 *
 * [1380] Lucky Numbers in a Matrix
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    vector<int> luckys;
    for (const auto& row : matrix) {
      int w = row.size();
      int min_index = -1;
      int min_value = INT_MAX;
      for (int i = 0; i < w; i++) {
        if (row[i] < min_value) {
          min_value = row[i];
          min_index = i;
        }
      }

      int h = matrix.size();
      bool is_lucky = true;
      for (int i = 0; i < h; i++) {
        if (matrix[i][min_index] > min_value) {
          is_lucky = false;
          break;
        }
      }
      if (is_lucky) {
        luckys.push_back(min_value);
      }
    }
    return luckys;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> matrix;
  vector<int> exp;

  matrix = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
  exp = {15};
  ASSERT_EQ(s.luckyNumbers(matrix), exp);

  matrix = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
  exp = {12};
  ASSERT_EQ(s.luckyNumbers(matrix), exp);

  matrix = {{7, 8}, {1, 2}};
  exp = {7};
  ASSERT_EQ(s.luckyNumbers(matrix), exp);
  return 0;
}
