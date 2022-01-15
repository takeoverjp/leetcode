/*
 * @lc app=leetcode id=1512 lang=cpp
 *
 * [1512] Number of Good Pairs
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numIdenticalPairs(vector<int>& nums) {
    int ret = 0;
    map<int, int> counts;
    for (auto num : nums) {
      counts[num]++;
    }
    for (auto& pair : counts) {
      ret += pair.second * (pair.second - 1) / 2;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  nums = {1, 2, 3, 1, 1, 3};
  ASSERT_EQ(s.numIdenticalPairs(nums), 4);
  nums = {1, 1, 1, 1};
  ASSERT_EQ(s.numIdenticalPairs(nums), 6);
  nums = {1, 2, 3};
  ASSERT_EQ(s.numIdenticalPairs(nums), 0);
  return 0;
}
