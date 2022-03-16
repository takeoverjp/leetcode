/*
 * @lc app=leetcode id=1869 lang=cpp
 *
 * [1869] Longer Contiguous Segments of Ones than Zeros
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkZeroOnes(string s) {
    int ones = 0;
    int zeros = 0;
    bool is_one = false;
    bool is_zero = false;
    int count = 0;
    for (const auto c : s) {
      if (count == 0) {
        count = 1;
        if (c == '0') {
          is_zero = true;
          zeros = max(zeros, count);
        } else {
          is_one = true;
          ones = max(ones, count);
        }
      } else if (is_zero) {
        if (c == '0') {
          count++;
          zeros = max(zeros, count);
        } else {
          is_zero = false;
          is_one = true;
          count = 1;
          ones = max(ones, count);
        }
      } else if (is_one) {
        if (c == '0') {
          is_one = false;
          is_zero = true;
          count = 1;
          zeros = max(zeros, count);
        } else {
          count++;
          ones = max(ones, count);
        }
      }
    }
    return ones > zeros;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.checkZeroOnes("10"), false);
  ASSERT_EQ(s.checkZeroOnes("1101"), true);
  ASSERT_EQ(s.checkZeroOnes("111000"), false);
  ASSERT_EQ(s.checkZeroOnes("110100010"), false);
  return 0;
}
