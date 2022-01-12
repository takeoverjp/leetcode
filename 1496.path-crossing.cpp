/*
 * @lc app=leetcode id=1496 lang=cpp
 *
 * [1496] Path Crossing
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isPathCrossing(string path) {
    int x = 0;
    int y = 0;
    set<pair<int, int>> points;
    points.insert({x, y});
    for (auto c : path) {
      switch (c) {
        case 'N':
          y++;
          break;
        case 'S':
          y--;
          break;
        case 'E':
          x++;
          break;
        case 'W':
          x--;
          break;
      }
      if (points.count({x, y})) {
        return true;
      }
      points.insert({x, y});
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.isPathCrossing("NES"), false);
  ASSERT_EQ(s.isPathCrossing("NESWW"), true);
  return 0;
}
