/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (const auto num : nums) {
      ret ^= num;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> vec;
  vec = {1};
  assert(s.singleNumber(vec) == 1);
  vec = {2, 2, 1};
  assert(s.singleNumber(vec) == 1);
  vec = {4, 1, 2, 1, 2};
  assert(s.singleNumber(vec) == 4);
  return 0;
}
