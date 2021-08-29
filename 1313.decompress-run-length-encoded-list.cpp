/*
 * @lc app=leetcode id=1313 lang=cpp
 *
 * [1313] Decompress Run-Length Encoded List
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> decompressRLElist(vector<int>& nums) {
    vector<int> ret;
    int size = nums.size();
    int ret_size = 0;
    for (int i = 0; i < size; i += 2) {
      ret_size += nums[i];
    }
    ret.reserve(ret_size);
    for (int i = 0; i < size; i += 2) {
      for (int j = 0; j < nums[i]; j++) {
        ret.push_back(nums[i + 1]);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums = {1, 2, 3, 4};
  vector<int> exp = {2, 4, 4, 4};
  ASSERT_EQ(s.decompressRLElist(nums), exp);
  nums = {1, 1, 2, 3};
  exp = {1, 3, 3};
  ASSERT_EQ(s.decompressRLElist(nums), exp);
  return 0;
}
