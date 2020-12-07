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
    unordered_map<int, int> count;
    for (int num : nums) {
      count[num]++;
      if (count[num] > nums.size() / 2) {
        return num;
      }
    }
    return 0;
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
