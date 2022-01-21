/*
 * @lc app=leetcode id=1582 lang=cpp
 *
 * [1582] Special Positions in a Binary Matrix
 */

// @lc code=start
class Solution {
 public:
  int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int ret = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          continue;
        }
        for (int k = 0; k < m; k++) {
          if (k == i) {
            continue;
          }
          if (mat[k][j]) {
            goto NEXT;
          }
        }
        for (int k = 0; k < n; k++) {
          if (k == j) {
            continue;
          }
          if (mat[i][k]) {
            goto NEXT;
          }
        }
        ret++;
      NEXT:;
      }
    }
    return ret;
  }
};
// @lc code=end
