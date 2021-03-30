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
    for (const int num : nums) {
      que_.push(num);
      if (static_cast<int>(que_.size()) > k) {
        que_.pop();
      }
    }
  }

  int add(int val) {
    que_.push(val);
    if (static_cast<int>(que_.size()) > k_) {
      que_.pop();
    }
    return que_.top();
  }

 private:
  const int k_;
  std::priority_queue<int, std::vector<int>, std::greater<int>> que_;
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
