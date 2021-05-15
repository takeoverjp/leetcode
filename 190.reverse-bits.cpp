/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0x0;
    for (int i = 0; i < 32; i++) {
      if (n & (1 << i)) {
        ret |= 1 << (31 - i);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.reverseBits(0b00000010100101000001111010011100),
            0b00111001011110000010100101000000);
  ASSERT_EQ(s.reverseBits(0b11111111111111111111111111111101),
            0b10111111111111111111111111111111);
  return 0;
}
