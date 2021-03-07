/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int max1 = INT_MIN;
    int max2 = INT_MIN;
    int max3 = INT_MIN;
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    for (const auto num : nums) {
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }
        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }
    return std::max(max1 * max2 * max3, max1 * min1 * min2);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2, 3};
  ASSERT_EQ(s.maximumProduct(nums), 6);
  nums = {1, 2, 3, 4};
  ASSERT_EQ(s.maximumProduct(nums), 24);
  nums = {-1, -2, -3};
  ASSERT_EQ(s.maximumProduct(nums), -6);

  return 0;
}
