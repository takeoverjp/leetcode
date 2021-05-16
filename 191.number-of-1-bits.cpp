/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
      if (n & 1) {
        ret++;
      }
      n >>= 1;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.hammingWeight(0b00000000000000000000000000001011), 3);
  ASSERT_EQ(s.hammingWeight(0b00000000000000000000000010000000), 1);
  ASSERT_EQ(s.hammingWeight(0b11111111111111111111111111111101), 31);
  return 0;
}
