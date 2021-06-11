/*
 * @lc app=leetcode id=944 lang=cpp
 *
 * [944] Delete Columns to Make Sorted
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int minDeletionSize(vector<string>& strs) {
    int ret = 0;
    int row_num = strs.size();
    int column_num = strs[0].length();
    for (int x = 0; x < column_num; x++) {
      char last = strs[0][x];
      for (int y = 1; y < row_num; y++) {
        if (strs[y][x] < last) {
          ret++;
          break;
        } else {
          last = strs[y][x];
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> strs;
  strs = {"cba", "daf", "ghi"};
  ASSERT_EQ(s.minDeletionSize(strs), 1);
  strs = {"a", "b"};
  ASSERT_EQ(s.minDeletionSize(strs), 0);
  strs = {"zyx", "wvu", "tsr"};
  ASSERT_EQ(s.minDeletionSize(strs), 3);
  return 0;
}
