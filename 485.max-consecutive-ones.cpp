/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ret = 0;
    int current = 0;
    for (const int num : nums) {
      if (num) {
        current++;
      } else {
        current = 0;
      }
      if (current > ret) {
        ret = current;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums = {1, 1, 0, 1, 1, 1};
  assert(s.findMaxConsecutiveOnes(nums) == 3);
  nums = {1};
  assert(s.findMaxConsecutiveOnes(nums) == 1);
  nums = {0};
  assert(s.findMaxConsecutiveOnes(nums) == 0);
  nums = {1, 1, 0, 1, 1, 1, 0, 1, 1};
  assert(s.findMaxConsecutiveOnes(nums) == 3);
  return 0;
}
