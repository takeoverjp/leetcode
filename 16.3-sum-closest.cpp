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
    int min_dist = INT_MAX;
    int ret = INT_MAX;
    int size = nums.size();
    for (int i = 0; i < size - 2; i++) {
      for (int j = i + 1; j < size - 1; j++) {
        for (int k = j + 1; k < size; k++) {
          int sum = nums[i] + nums[j] + nums[k];
          int distance = abs(sum - target);
          if (distance < min_dist) {
            min_dist = distance;
            ret = sum;
          }
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
  vector<int> large(1000);
  for (auto& num : large) {
    num = 1000;
  }
  ASSERT_EQ(s.threeSumClosest(large, 1), 3000);
  return 0;
}
