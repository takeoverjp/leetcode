/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int size = height.size();
    int ret = 0;
    for (int left = 0; left < size - 1; left++) {
      for (int right = left + 1; right < size; right++) {
        int rect_h = std::min(height[left], height[right]);
        ret = max(ret, rect_h * (right - left));
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> height;
  height = {1,8,6,2,5,4,8,3,7};
  ASSERT_EQ(s.maxArea(height), 49);
  height = {1, 1};
  ASSERT_EQ(s.maxArea(height), 1);
  height = {4, 3, 2, 1, 4};
  ASSERT_EQ(s.maxArea(height), 16);
  height = {1, 2, 1};
  ASSERT_EQ(s.maxArea(height), 2);
  return 0;
}
