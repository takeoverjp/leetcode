/*
 * @lc app=leetcode id=812 lang=cpp
 *
 * [812] Largest Triangle Area
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  double largestTriangleArea(vector<vector<int>>& points) {
    int size = points.size();
    int ret = INT_MIN;
    for (int i = 0; i < size - 2; i++) {
      for (int j = i + 1; j < size - 1; j++) {
        for (int k = j + 1; k < size; k++) {
          int area = points[i][0] * points[j][1] + points[j][0] * points[k][1] +
                     points[k][0] * points[i][1] - points[i][0] * points[k][1] -
                     points[j][0] * points[i][1] - points[k][0] * points[j][1];
          ret = std::max(ret, std::abs(area));
        }
      }
    }
    return static_cast<double>(ret) / 2.0;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> points;
  points = {{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}};
  ASSERT_EQ(s.largestTriangleArea(points), 2);
  points = {{1, 0}, {0, 0}, {0, 1}};
  ASSERT_EQ(s.largestTriangleArea(points), 0.5);
  points = {{2, 5}, {7, 7}, {10, 8}, {10, 10}, {1, 1}};
  ASSERT_EQ(s.largestTriangleArea(points), 14.5);
  return 0;
}
