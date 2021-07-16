/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ret;
    for (int i = 0; i <= n; i++) {
      ret.push_back(__builtin_popcount(i));
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  std::vector<int> nums;
  nums = {0, 1, 1};
  ASSERT_EQ(s.countBits(2), nums);
  nums = {0, 1, 1, 2, 1, 2};
  ASSERT_EQ(s.countBits(5), nums);
  nums = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
          1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5};
  ASSERT_EQ(s.countBits(31), nums);
  return 0;
}
