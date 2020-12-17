/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_map<int, bool> map;
    for (auto num : nums) {
      if (map[num]) {
        return true;
      }
      map[num] = true;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2, 3, 1};
  assert(s.containsDuplicate(nums) == true);
  nums = {1, 2, 3, 4};
  assert(s.containsDuplicate(nums) == false);
  nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  assert(s.containsDuplicate(nums) == true);
  return 0;
}
