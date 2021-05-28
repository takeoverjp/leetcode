/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& nums) {
    int size = nums.size();
    int odd = 1;
    for (int even = 0; even < size; even += 2) {
      if (nums[even] % 2 == 0) {
        continue;
      }

      /* need swap */
      for (; odd < size; odd += 2) {
        if (nums[odd] % 2 == 0) {
          break;
        }
      }
      int tmp = nums[odd];
      nums[odd] = nums[even];
      nums[even] = tmp;
    }
    return nums;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {4, 2, 5, 7};
  ASSERT_EQ(s.sortArrayByParityII(nums), vector<int>({4, 5, 2, 7}));
  nums = {2, 3};
  ASSERT_EQ(s.sortArrayByParityII(nums), vector<int>({2, 3}));
  return 0;
}
