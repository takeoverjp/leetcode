/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int len = nums.size();
    int max = INT32_MIN;
    for (int i = 0; i < len; i++) {
      int sum = 0;
      for (int j = i; j < len; j++) {
        sum += nums[j];
        if (max < sum) {
          max = sum;
        }
      }
    }
    return max;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  assert(s.maxSubArray(nums) == 6);
  nums = {1};
  assert(s.maxSubArray(nums) == 1);
  nums = {0};
  assert(s.maxSubArray(nums) == 0);
  nums = {-1};
  assert(s.maxSubArray(nums) == -1);
  nums = {-2147483647};
  assert(s.maxSubArray(nums) == -2147483647);
  nums = {-2147483647, -1};
  assert(s.maxSubArray(nums) == -1);
  return 0;
}
