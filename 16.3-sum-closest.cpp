/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ret = INT_MAX;
    int min_dist = INT_MAX;
    int size = nums.size();
    for (int left = 0; left < size - 2; left++) {
      int middle = left + 1;
      int right = size - 1;
      while (middle < right) {
        int sum = nums[left] + nums[middle] + nums[right];
        if (sum == target) {
          return target;
        }
        int dist = abs(sum - target);
        if (dist < min_dist) {
          min_dist = dist;
          ret = sum;
        }
        if (sum < target) {
          middle++;
        } else {
          right--;
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {-1, 2, 1, -4};
  ASSERT_EQ(s.threeSumClosest(nums, 1), 2);
  nums = {-1, 2, 1, -4, 0};
  ASSERT_EQ(s.threeSumClosest(nums, 1), 1);
  nums = {-1, 2, 9, -4, -1};
  ASSERT_EQ(s.threeSumClosest(nums, 1), 0);
  vector<int> large(1000, 1000);
  ASSERT_EQ(s.threeSumClosest(large, 1), 3000);
  vector<int> min_large(1000, -1000);
  ASSERT_EQ(s.threeSumClosest(min_large, 1), -3000);
  return 0;
}
