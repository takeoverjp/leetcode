/*
 * @lc app=leetcode id=703 lang=cpp
 *
 * [703] Kth Largest Element in a Stream
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class KthLargest {
 public:
  KthLargest(int k, vector<int>& nums) : k_(k) {
    std::sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
    const int size = nums.size();
    const int last = std::min(size, k);
    for (int i = 0; i < last; i++) {
      nums_.push_back(nums[i]);
    }
  }

  int add(int val) {
    for (auto it = nums_.begin(); it != nums_.end(); it++) {
      if (val > *it) {
        nums_.insert(it, val);
        int size = nums_.size();
        if (size > k_) {
          nums_.pop_back();
        }
        break;
      }
    }
    if (nums_.size() < k_) {
      nums_.push_back(val);
    }
    return nums_[k_ - 1];
  }

 private:
  const int k_;
  vector<int> nums_;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
// @lc code=end

int main() {
  vector<int> nums;
  {
    nums = {4, 5, 8, 2};
    KthLargest k(3, nums);
    ASSERT_EQ(k.add(3), 4);
    ASSERT_EQ(k.add(5), 5);
    ASSERT_EQ(k.add(10), 5);
    ASSERT_EQ(k.add(9), 8);
    ASSERT_EQ(k.add(4), 8);
  }
  {
    nums = {};
    KthLargest k(1, nums);
    ASSERT_EQ(k.add(-3), -3);
    ASSERT_EQ(k.add(-2), -2);
    ASSERT_EQ(k.add(-4), -2);
    ASSERT_EQ(k.add(0), 0);
    ASSERT_EQ(k.add(4), 4);
  }
  {
    nums = {0};
    KthLargest k(2, nums);
    ASSERT_EQ(k.add(-1), -1);
    ASSERT_EQ(k.add(1), 0);
    ASSERT_EQ(k.add(-2), 0);
    ASSERT_EQ(k.add(-4), 0);
    ASSERT_EQ(k.add(3), 1);
  }
  return 0;
}
