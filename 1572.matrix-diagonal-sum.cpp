/*
 * @lc app=leetcode id=1572 lang=cpp
 *
 * [1572] Matrix Diagonal Sum
 */

// @lc code=start
class Solution {
 public:
  int diagonalSum(vector<vector<int>>& mat) {
    int sum = 0;
    int size = mat.size();
    for (int i = 0; i < size; i++) {
      sum += mat[i][i] + mat[i][size - i - 1];
    }
    if (size % 2) {
      sum -= mat[size / 2][size / 2];
    }
    return sum;
  }
};
// @lc code=end
