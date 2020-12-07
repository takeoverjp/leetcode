/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int candidate = nums[0];
    int count = 0;
    for (int num : nums) {
      if (count == 0) candidate = num;
      count += (candidate == num) ? 1 : -1;
    }
    return candidate;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {3, 2, 3};
  assert(s.majorityElement(nums) == 3);
  nums = {2, 2, 1, 1, 1, 2, 2};
  assert(s.majorityElement(nums) == 2);
  return 0;
}
