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
    int ret = 0;
    for (int i = 0; i < size - 2; i++) {
      for (int j = i + 1; j < size - 1; j++) {
        for (int k = j + 1; k < size; k++) {
          int minx = min(min(points[i][0], points[j][0]), points[k][0]);
          int maxx = max(max(points[i][0], points[j][0]), points[k][0]);
          int miny = min(min(points[i][1], points[j][1]), points[k][1]);
          int maxy = max(max(points[i][1], points[j][1]), points[k][1]);
          int rect = (maxx - minx) * (maxy - miny) * 2;
          int triij = abs((points[i][0] - points[j][0]) *
                          (points[i][1] - points[j][1]));
          int trijk = abs((points[j][0] - points[k][0]) *
                          (points[j][1] - points[k][1]));
          int triki = abs((points[k][0] - points[i][0]) *
                          (points[k][1] - points[i][1]));
          cout << "points = " << points[i][0] << "," << points[i][1] << ","
               << points[j][0] << "," << points[j][1] << "," << points[k][0]
               << "," << points[k][1] << endl;
          cout << "rect = " << rect << endl;
          cout << "tri = " << triij << "," << trijk << "," << triki << endl;
          ret = max(ret, rect - triij - trijk - triki);
          cout << "ret = " << ret << endl;
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
  points = {{2, 5}, {7, 7}, {10, 8}, {10, 10}, {1, 1}};
  ASSERT_EQ(s.largestTriangleArea(points), 14.5);
  return 0;
}
