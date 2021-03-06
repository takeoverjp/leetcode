/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int size = nums.size();
    // val, index
    std::unordered_map<int, int> dict;
    for (int i = 0; i < size; i++) {
      int n = nums[i];
      int m = target - n;
      if (dict.count(m)) {
        return {dict[m], i};
      } else {
        dict[n] = i;
      }
    }
    return {};
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {2, 7, 11, 15};
  ASSERT_EQ(s.twoSum(nums, 9), std::vector<int>({0, 1}));
  nums = {3, 2, 4};
  ASSERT_EQ(s.twoSum(nums, 6), std::vector<int>({1, 2}));
  nums = {3, 3};
  ASSERT_EQ(s.twoSum(nums, 6), std::vector<int>({0, 1}));
  return 0;
}
