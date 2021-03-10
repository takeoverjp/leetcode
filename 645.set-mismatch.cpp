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
    map<int, int> result;
    for (const auto num : nums) {
      if (result[num]) {
        ret.push_back(num);
      }
      result[num] = true;
    }
    int size = nums.size();
    for (int i = 1; i <= size; i++) {
      if (result[i] == 0) {
        ret.push_back(i);
        return ret;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {1, 2, 2, 4};
  exp = {2, 3};
  assert(s.findErrorNums(nums) == exp);
  nums = {1, 1};
  exp = {1, 2};
  assert(s.findErrorNums(nums) == exp);
  nums = {1, 2, 2, 4};
  exp = {2, 3};
  assert(s.findErrorNums(nums) == exp);
  return 0;
}
