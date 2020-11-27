/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ret;
    for (int i = 0; i < numRows; i++) {
      vector<int> row;
      for (int j = 0; j < i + 1; j++) {
        if ((j == 0) || (j == i)) {
          row.push_back(1);
        } else {
          row.push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
        }
      }
      ret.push_back(row);
    }
    return ret;
  }
};
// @lc code=end
