/*
 * @lc app=leetcode id=1232 lang=cpp
 *
 * [1232] Check If It Is a Straight Line
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    int start_x = coordinates[0][0];
    int start_y = coordinates[0][1];
    int64_t diff_x0 = coordinates[1][0] - start_x;
    int64_t diff_y0 = coordinates[1][1] - start_y;
    int size = coordinates.size();
    for (int i = 2; i < size; i++) {
      int64_t diff_x = coordinates[i][0] - start_x;
      int64_t diff_y = coordinates[i][1] - start_y;
      if (diff_y0 * diff_x != diff_x0 * diff_y) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> coordinates;
  coordinates = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
  ASSERT_EQ(s.checkStraightLine(coordinates), true);
  coordinates = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
  ASSERT_EQ(s.checkStraightLine(coordinates), false);
  return 0;
}
