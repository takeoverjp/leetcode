/*
 * @lc app=leetcode id=1608 lang=cpp
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int specialArray(vector<int>& nums) {
    int size = nums.size();
    for (int x = 0; x <= size; x++) {
      if (count_if(nums.begin(), nums.end(),
                   [x](auto num) { return num >= x; }) == x) {
        return x;
      }
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {3, 5};
  ASSERT_EQ(s.specialArray(nums), 2);
  nums = {0, 0};
  ASSERT_EQ(s.specialArray(nums), -1);
  nums = {0, 4, 3, 0, 4};
  ASSERT_EQ(s.specialArray(nums), 3);
  return 0;
}
