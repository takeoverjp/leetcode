/*
 * @lc app=leetcode id=1323 lang=cpp
 *
 * [1323] Maximum 69 Number
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maximum69Number(int num) {
    for (int i = 1000; i >= 1; i /= 10) {
      int digit = (num % (i * 10)) / i;
      if (digit == 6) {
        return num + 3 * i;
      }
    }
    return num;
  }
};
// @lc code=end

int
main () {
  Solution s;
  ASSERT_EQ(s.maximum69Number(9669), 9969);
  ASSERT_EQ(s.maximum69Number(9996), 9999);
  ASSERT_EQ(s.maximum69Number(9999), 9999);
  ASSERT_EQ(s.maximum69Number(9), 9);
  ASSERT_EQ(s.maximum69Number(6), 9);
  return 0;
}
