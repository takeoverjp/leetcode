/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findNumbers(vector<int>& nums) {
    int ret = 0;
    for (int num : nums) {
      bool is_even = true;
      while (num) {
        num /= 10;
        is_even = !is_even;
      }
      if (is_even) {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {12, 345, 2, 6, 7896};
  ASSERT_EQ(s.findNumbers(nums), 2);
  nums = {555, 901, 482, 1771};
  ASSERT_EQ(s.findNumbers(nums), 1);
  return 0;
}
