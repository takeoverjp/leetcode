/*
 * @lc app=leetcode id=1030 lang=cpp
 *
 * [1030] Matrix Cells in Distance Order
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter,
                                        int cCenter) {
    vector<vector<int>> ret;
    for (int row = 0; row < rows; row++) {
      for (int col = 0; col < cols; col++) {
        ret.push_back({row, col});
      }
    }
    std::sort(ret.begin(), ret.end(),
              [rCenter, cCenter](const auto& lhs, const auto& rhs) {
                return (abs(lhs[0] - rCenter) + abs(lhs[1] - cCenter)) <
                       (abs(rhs[0] - rCenter) + abs(rhs[1] - cCenter));
              });
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> exp;
  exp = {{0, 0}, {0, 1}};
  ASSERT_EQ(s.allCellsDistOrder(1, 2, 0, 0), exp);
  exp = {{0, 1}, {0, 0}, {1, 1}, {1, 0}};
  ASSERT_EQ(s.allCellsDistOrder(2, 2, 0, 1), exp);
  exp = {{1, 2}, {0, 2}, {1, 1}, {0, 1}, {1, 0}, {0, 0}};
  ASSERT_EQ(s.allCellsDistOrder(2, 3, 1, 2), exp);
  return 0;
}
