/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findGCD(vector<int>& nums) {
    sort(begin(nums), end(nums));
    int max_cand = nums[nums.size() - 1];
    int min_cand = nums[0];
    while (max_cand - min_cand > 1) {
      int a = max_cand - min_cand;
      if (a > min_cand) {
        max_cand = a;
      } else {
        max_cand = min_cand;
        min_cand = a;
      }
    }
    return (max_cand == min_cand) ? max_cand : 1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {2, 5, 6, 9, 10};
  ASSERT_EQ(s.findGCD(nums), 2);
  nums = {7, 5, 6, 8, 3};
  ASSERT_EQ(s.findGCD(nums), 1);
  nums = {3, 3};
  ASSERT_EQ(s.findGCD(nums), 3);
  return 0;
}
