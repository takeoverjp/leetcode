/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < len; i++) {
      if (i != nums[i]) {
        return i;
      }
    }
    return len;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums = {3, 0, 1};
  assert(s.missingNumber(nums) == 2);
  nums = {0, 1};
  assert(s.missingNumber(nums) == 2);
  nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  assert(s.missingNumber(nums) == 8);
  nums = {0};
  assert(s.missingNumber(nums) == 1);
  return 0;
}
