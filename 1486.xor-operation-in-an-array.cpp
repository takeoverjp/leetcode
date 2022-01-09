/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int xorOperation(int n, int start) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
      ret ^= start;
      start += 2;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.xorOperation(5, 0), 8);
  ASSERT_EQ(s.xorOperation(4, 3), 8);
  return 0;
}
