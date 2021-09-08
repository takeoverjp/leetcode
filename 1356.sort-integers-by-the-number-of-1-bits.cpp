/*
 * @lc app=leetcode id=1356 lang=cpp
 *
 * [1356] Sort Integers by The Number of 1 Bits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> sortByBits(vector<int>& arr) {
    std::sort(std::begin(arr), std::end(arr), [](int lhs, int rhs) {
#if 1
      int lbits = __builtin_popcount(lhs);
      int rbits = __builtin_popcount(rhs);
#else
      int lbits = std::bitset<sizeof(int) * 8>(lhs).count();
      int rbits = std::bitset<sizeof(int) * 8>(rhs).count();
#endif
      return lbits == rbits ? (lhs < rhs) : (lbits < rbits);
    });
    return arr;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr, exp;
  arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  exp = {0, 1, 2, 4, 8, 3, 5, 6, 7};
  ASSERT_EQ(s.sortByBits(arr), exp);

  arr = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
  exp = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
  ASSERT_EQ(s.sortByBits(arr), exp);

  arr = {10000, 10000};
  exp = {10000, 10000};
  ASSERT_EQ(s.sortByBits(arr), exp);

  arr = {2, 3, 5, 7, 11, 13, 17, 19};
  exp = {2, 3, 5, 17, 7, 11, 13, 19};
  ASSERT_EQ(s.sortByBits(arr), exp);

  arr = {10, 100, 1000, 10000};
  exp = {10, 100, 10000, 1000};
  ASSERT_EQ(s.sortByBits(arr), exp);
  return 0;
}
