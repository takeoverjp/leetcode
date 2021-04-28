/*
 * @lc app=leetcode id=836 lang=cpp
 *
 * [836] Rectangle Overlap
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int w1 = rec1[2] - rec1[0];
    int h1 = rec1[3] - rec1[1];
    int w2 = rec2[2] - rec2[0];
    int h2 = rec2[3] - rec2[1];
    if (!w1 || !h1 || !w2 || !h2) {
      return false;
    }
    if (((rec1[0] < rec2[0] && rec2[0] < rec1[2]) ||
         (rec2[0] < rec1[0] && rec1[0] < rec2[2]) ||
         (rec1[0] < rec2[2] && rec2[2] < rec1[2]) ||
         (rec2[0] < rec1[2] && rec1[2] < rec2[2])) &&
        ((rec1[1] < rec2[1] && rec2[1] < rec1[3]) ||
         (rec2[1] < rec1[1] && rec1[1] < rec2[3]) ||
         (rec1[1] < rec2[3] && rec2[3] < rec1[3]) ||
         (rec2[1] < rec1[3] && rec1[3] < rec2[3]))) {
      return true;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> rec1, rec2;
  rec1 = {0, 0, 2, 2};
  rec2 = {1, 1, 3, 3};
  ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), true);
  rec1 = {0, 0, 1, 1};
  rec2 = {1, 0, 2, 1};
  ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), false);
  rec1 = {0, 0, 1, 1};
  rec2 = {2, 2, 3, 3};
  ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), false);
  rec1 = {1, 1, 1, 2};
  rec2 = {0, 0, 2, 2};
  ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), false);
  rec1 = {11, 12, 13, 13};
  rec2 = {17, 1, 17, 19};
  ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), false);
  rec1 = {7, 8, 13, 15};
  rec2 = {10, 8, 12, 20};
  ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), true);
  rec1 = {-1, 0, 1, 1};
  rec2 = {0, -1, 0, 1};
  ASSERT_EQ(s.isRectangleOverlap(rec1, rec2), false);
  return 0;
}
