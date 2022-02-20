/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> num_count;
    for (const auto num : nums) {
      num_count[num]++;
    }
    int ret = 0;
    for (const auto& pair : num_count) {
      if (pair.second == 1) {
        ret += pair.first;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2, 3, 2};
  ASSERT_EQ(s.sumOfUnique(nums), 4);
  nums = {1, 1, 1, 1, 1};
  ASSERT_EQ(s.sumOfUnique(nums), 0);
  nums = {1, 2, 3, 4, 5};
  ASSERT_EQ(s.sumOfUnique(nums), 15);
  return 0;
}
