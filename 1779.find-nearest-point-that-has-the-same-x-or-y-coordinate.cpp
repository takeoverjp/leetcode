/*
 * @lc app=leetcode id=1779 lang=cpp
 *
 * [1779] Find Nearest Point That Has the Same X or Y Coordinate
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int min_dist = INT_MAX;
    int ret = -1;
    int size = points.size();
    for (int i = 0; i < size; i++) {
      if (points[i][0] != x && points[i][1] != y) {
        continue;
      }
      int cur_dist = abs(points[i][0] - x) + abs(points[i][1] - y);
      if (min_dist > cur_dist) {
        min_dist = cur_dist;
        ret = i;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> points;
  points = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
  ASSERT_EQ(s.nearestValidPoint(3, 4, points), 2);
  points = {{3, 4}};
  ASSERT_EQ(s.nearestValidPoint(3, 4, points), 0);
  points = {{2, 3}};
  ASSERT_EQ(s.nearestValidPoint(3, 4, points), -1);
  return 0;
}
