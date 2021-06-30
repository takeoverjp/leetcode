/*
 * @lc app=leetcode id=1033 lang=cpp
 *
 * [1033] Moving Stones Until Consecutive
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> numMovesStones(int a, int b, int c) {
    vector<int> nums{a, b, c};
    sort(nums.begin(), nums.end());
    vector<int> ret(2);
    ret[1] = nums[2] - nums[0] - 2;

    if (ret[1] == 0) {
        ret[0] = 0;
    } else if (nums[1] - nums[0] <= 2 || nums[2] - nums[1] <= 2) {
        ret[0] = 1;
    } else {
        ret[0] = 2;
    }

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.numMovesStones(1, 2, 5), vector<int>({1, 2}));
  ASSERT_EQ(s.numMovesStones(4, 3, 2), vector<int>({0, 0}));
  ASSERT_EQ(s.numMovesStones(3, 5, 1), vector<int>({1, 2}));
  return 0;
}
