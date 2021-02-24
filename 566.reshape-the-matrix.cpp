/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    if (nums.size() * nums[0].size() != r * c) {
      return nums;
    }
    vector<vector<int>> rets;
    int idx = 0;
    for (const auto& vec : nums) {
      for (const auto num : vec) {
        if (idx % c == 0) {
          rets.push_back({});
        }
        rets[rets.size() - 1].push_back(num);
        ++idx;
      }
    }
    return rets;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> nums, exp;
  nums = {{1, 2}, {3, 4}};
  exp = {{1, 2}, {3, 4}};
  assert(s.matrixReshape(nums, 2, 4) == exp);
  nums = {{1, 2}, {3, 4}};
  exp = {{1, 2, 3, 4}};
  assert(s.matrixReshape(nums, 1, 4) == exp);
  nums = {{1, 2, 3, 4}};
  exp = {{1, 2}, {3, 4}};
  assert(s.matrixReshape(nums, 2, 2) == exp);
  return 0;
}
