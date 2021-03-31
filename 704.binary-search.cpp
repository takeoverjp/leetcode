/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    return search(nums, 0, nums.size() - 1, target);
  }

 private:
  int search(vector<int>& nums, int start, int end, int target) {
    if (start == end) {
      return (nums[start] == target) ? start : -1;
    }
    int mid = (start + end) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] < target) {
      return search(nums, min(mid + 1, end), end, target);
    } else {
      return search(nums, start, max(start, mid - 1), target);
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {-1, 0, 3, 5, 9, 12};
  ASSERT_EQ(s.search(nums, 9), 4);
  nums = {-1, 0, 3, 5, 9, 12};
  ASSERT_EQ(s.search(nums, 2), -1);
  nums = {5};
  ASSERT_EQ(s.search(nums, 5), 0);
  nums = {5};
  ASSERT_EQ(s.search(nums, -5), -1);
  nums = {4, 5};
  ASSERT_EQ(s.search(nums, 5), 1);
  nums = {4, 5};
  ASSERT_EQ(s.search(nums, -5), -1);
  return 0;
}
