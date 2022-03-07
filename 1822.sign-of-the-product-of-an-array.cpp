/*
 * @lc app=leetcode id=1822 lang=cpp
 *
 * [1822] Sign of the Product of an Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int arraySign(vector<int>& nums) {
    int ret = 1;
    for (int num : nums) {
      if (num == 0) {
        return 0;
      } else if (num < 0) {
        ret *= -1;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {-1, -2, -3, -4, 3, 2, 1};
  ASSERT_EQ(s.arraySign(nums), 1);
  nums = {1, 5, 0, 2, -3};
  ASSERT_EQ(s.arraySign(nums), 0);
  nums = {-1, 1, -1, 1, -1};
  ASSERT_EQ(s.arraySign(nums), -1);
  return 0;
}
