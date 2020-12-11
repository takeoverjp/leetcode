/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i % 2) {
        a = max(a + nums[i], b);
      } else {
        b = max(a, b + nums[i]);
      }
    }
    return max(a, b);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2, 3, 1};
  assert(s.rob(nums) == 4);
  nums = {2, 7, 9, 3, 1};
  assert(s.rob(nums) == 12);
  nums = {1, 7, 2, 3, 9, 1};
  assert(s.rob(nums) == 16);
  return 0;
}
