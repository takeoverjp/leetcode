/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int dominantIndex(vector<int>& nums) {
    int size = nums.size();
    if (size < 2) {
      return 0;
    }
    int largest = INT_MIN;
    int largest_idx = -1;
    int second = INT_MIN;
    int second_idx = -1;
    for (int i = 0; i < size; i++) {
      if (nums[i] >= largest) {
        second = largest;
        second_idx = largest_idx;
        largest = nums[i];
        largest_idx = i;
      } else if (nums[i] > second) {
        second = nums[i];
        second_idx = i;
      }
    }
    return (largest >= 2 * second) ? largest_idx : -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {3};
  ASSERT_EQ(s.dominantIndex(nums), 0);
  nums = {3, 6, 1, 0};
  ASSERT_EQ(s.dominantIndex(nums), 1);
  nums = {1, 2, 3, 4};
  ASSERT_EQ(s.dominantIndex(nums), -1);
  return 0;
}
