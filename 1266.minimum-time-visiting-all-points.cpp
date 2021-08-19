/*
 * @lc app=leetcode id=1266 lang=cpp
 *
 * [1266] Minimum Time Visiting All Points
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int ret = 0;
    int size = points.size();
    for (int i = 0; i < size - 1; i++) {
      ret += std::max(std::abs(points[i][0] - points[i + 1][0]),
                      std::abs(points[i][1] - points[i + 1][1]));
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> points;
  points = {{1, 1}, {3, 4}, {-1, 0}};
  ASSERT_EQ(s.minTimeToVisitAllPoints(points), 7);
  points = {{3, 2}, {-2, 2}};
  ASSERT_EQ(s.minTimeToVisitAllPoints(points), 5);
  return 0;
}
