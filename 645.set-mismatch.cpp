/*
 * @lc app=leetcode id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    vector<int> ret;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[abs(nums[i]) - 1] < 0) {
        ret.push_back(abs(nums[i]));
      } else {
        nums[abs(nums[i]) - 1] *= -1;
      }
    }
    for (int i = 0; i < size; i++) {
      // cout << "" << i << ", " << nums[i] << endl;
      if (nums[i] > 0) {
        ret.push_back(i + 1);
        break;
      }
    }

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {1, 2, 2, 3, 4};
  exp = {2, 5};
  assert(s.findErrorNums(nums) == exp);
  nums = {1, 2, 2};
  exp = {2, 3};
  assert(s.findErrorNums(nums) == exp);
  nums = {1, 3, 3, 4};
  exp = {3, 2};
  assert(s.findErrorNums(nums) == exp);
  nums = {1, 1};
  exp = {1, 2};
  assert(s.findErrorNums(nums) == exp);
  nums = {1, 4, 2, 5, 2};
  exp = {2, 3};
  assert(s.findErrorNums(nums) == exp);
  return 0;
}
