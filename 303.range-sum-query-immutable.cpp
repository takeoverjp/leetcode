/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class NumArray {
 public:
  NumArray(vector<int>& nums) : sums_(nums.size() + 1, 0) {
    std::partial_sum(nums.begin(), nums.end(), sums_.begin() + 1);
  }

  int sumRange(int left, int right) { return sums_[right + 1] - sums_[left]; }

 private:
  vector<int> sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

int main() {
  std::vector<int> nums{-2, 0, 3, -5, 2, -1};
  NumArray numArray(nums);
  ASSERT_EQ(numArray.sumRange(0, 2), 1);
  ASSERT_EQ(numArray.sumRange(2, 5), -1);
  ASSERT_EQ(numArray.sumRange(0, 5), -3);
  return 0;
}
