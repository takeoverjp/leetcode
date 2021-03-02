/*
 * @lc app=leetcode id=598 lang=cpp
 *
 * [598] Range Addition II
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;



// @lc code=start
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_row = m;
        int min_col = n;
        for (const auto& op : ops) {
            min_row = std::min(min_row, op[0]);
            min_col = std::min(min_col, op[1]);
        }
        return min_row * min_col;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<vector<int>> ops;
  ops = {{2,2},{3,3}};
  ASSERT_EQ(s.maxCount(3, 3, ops), 4);

    ops = {{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3},{2,2},{3,3},{3,3},{3,3}};
  ASSERT_EQ(s.maxCount(3, 3, ops), 4);

    ops = {};
  ASSERT_EQ(s.maxCount(3, 3, ops), 9);

  return 0;
}
