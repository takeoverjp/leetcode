/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    nums.resize(n * 2);
    for (int i = 0; i < n; i++) {
      nums[i + n] = nums[i];
    }
    return nums;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {1, 2, 1};
  exp = {1, 2, 1, 1, 2, 1};
  ASSERT_EQ(s.getConcatenation(nums), exp);
  nums = {1, 3, 2, 1};
  exp = {1, 3, 2, 1, 1, 3, 2, 1};
  ASSERT_EQ(s.getConcatenation(nums), exp);
  return 0;
}
