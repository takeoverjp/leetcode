/*
 * @lc app=leetcode id=1464 lang=cpp
 *
 * [1464] Maximum Product of Two Elements in an Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int first = INT_MIN, second = INT_MIN;
    for (auto num : nums) {
      if (num > first) {
        second = first;
        first = num;
      } else if (num > second) {
        second = num;
      }
    }
    return (first - 1) * (second - 1);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {3, 4, 5, 2};
  ASSERT_EQ(s.maxProduct(nums), 12);
  nums = {1, 5, 4, 5};
  ASSERT_EQ(s.maxProduct(nums), 16);
  nums = {3, 7};
  ASSERT_EQ(s.maxProduct(nums), 12);
  return 0;
}
