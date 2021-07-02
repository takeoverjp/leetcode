/*
 * @lc app=leetcode id=1037 lang=cpp
 *
 * [1037] Valid Boomerang
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isBoomerang(vector<vector<int>>& points) {
    if (points[0] == points[1] || points[1] == points[2] ||
        points[2] == points[0]) {
      return false;
    }
    int x1 = points[1][0] - points[0][0];
    int y1 = points[1][1] - points[0][1];
    int x2 = points[2][0] - points[1][0];
    int y2 = points[2][1] - points[1][1];

    return x2 * y1 != x1 * y2;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> points;
  points = {{1, 1}, {1, 1}, {3, 2}};
  ASSERT_EQ(s.isBoomerang(points), false);
  points = {{1, 1}, {3, 2}, {1, 1}};
  ASSERT_EQ(s.isBoomerang(points), false);
  points = {{3, 2}, {1, 1}, {1, 1}};
  ASSERT_EQ(s.isBoomerang(points), false);
  points = {{1, 1}, {2, 3}, {3, 2}};
  ASSERT_EQ(s.isBoomerang(points), true);
  points = {{1, 1}, {2, 1}, {1, 2}};
  ASSERT_EQ(s.isBoomerang(points), true);
  points = {{1, 1}, {2, 2}, {3, 3}};
  ASSERT_EQ(s.isBoomerang(points), false);
  return 0;
}
