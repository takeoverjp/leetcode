/*
 * @lc app=leetcode id=868 lang=cpp
 *
 * [868] Binary Gap
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int binaryGap(int n) {
    int ret = 0;
    int count = 0;
    int last = -1;
    while (n > (0b1 << count)) {
      if (n & (0b1 << count)) {
        if (last < 0) {
          last = count;
        } else {
          ret = std::max(ret, count - last);
          last = count;
        }
      }
      count++;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.binaryGap(0b10110), 2);
  ASSERT_EQ(s.binaryGap(0b101), 2);
  ASSERT_EQ(s.binaryGap(0b110), 1);
  ASSERT_EQ(s.binaryGap(0b1000), 0);
  ASSERT_EQ(s.binaryGap(0b1), 0);
  return 0;
}
