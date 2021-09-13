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
    std::vector<int> ret;
    std::set<int> mins, maxs;
    for (const auto& row : matrix) {
      mins.insert(*std::min_element(row.begin(), row.end()));
    }

    int h = matrix.size();
    int w = matrix[0].size();
    for (int i = 0; i < w; i++) {
      int max_value = INT_MIN;
      for (int j = 0; j < h; j++) {
        max_value = max(max_value, matrix[j][i]);
      }
      maxs.insert(max_value);
    }

    std::set_intersection(mins.begin(), mins.end(), maxs.begin(), maxs.end(),
                          std::back_inserter(ret));
    return ret;
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
