/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> ret;
    int base_10 = 0;
    for (const int num : nums) {
      base_10 = ((base_10 << 1) | num) % 5;
      ret.push_back(base_10 == 0);
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  vector<bool> exp;
  nums = {0, 1, 1};
  exp = {true, false, false};
  ASSERT_EQ(s.prefixesDivBy5(nums), exp);
  nums = {1, 1, 1};
  exp = {false, false, false};
  ASSERT_EQ(s.prefixesDivBy5(nums), exp);
  nums = {0, 1, 1, 1, 1, 1};
  exp = {true, false, false, false, true, false};
  ASSERT_EQ(s.prefixesDivBy5(nums), exp);
  nums = {1, 1, 1, 0, 1};
  exp = {false, false, false, false, false};
  ASSERT_EQ(s.prefixesDivBy5(nums), exp);
  return 0;
}
