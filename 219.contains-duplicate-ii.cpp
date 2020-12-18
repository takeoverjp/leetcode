/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    set<int> num_set;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (i > k) {
        num_set.erase(nums[i - k - 1]);
      }
      auto ret = num_set.insert(nums[i]);
      if (!ret.second) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2};
  assert(s.containsNearbyDuplicate(nums, 2) == false);
  nums = {1, 2, 1};
  assert(s.containsNearbyDuplicate(nums, 0) == false);
  nums = {1, 2, 3, 1};
  assert(s.containsNearbyDuplicate(nums, 3) == true);
  nums = {1, 0, 1, 1};
  assert(s.containsNearbyDuplicate(nums, 1) == true);
  nums = {1, 2, 3, 1, 2, 3};
  assert(s.containsNearbyDuplicate(nums, 2) == false);
  nums = {1, 2, 3, 2, 5};
  assert(s.containsNearbyDuplicate(nums, 3) == true);
  nums = {99, 99};
  assert(s.containsNearbyDuplicate(nums, 2) == true);
  return 0;
}
