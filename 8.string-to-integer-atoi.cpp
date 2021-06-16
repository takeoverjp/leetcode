/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {
    enum State {
      kSpaceState,
      kSignState,
      kDigitState,
    } state = kSpaceState;
    bool is_negative = false;
    uint64_t ret = 0;
    for (const char c : s) {
      if (state == kSpaceState) {
        if (isspace(c)) {
          continue;
        } else {
          state = kSignState;
        }
      }
      if (state == kSignState) {
        if (c == '-') {
          is_negative = true;
          state = kDigitState;
          continue;
        } else if (c == '+') {
          state = kDigitState;
          continue;
        } else {
          state = kDigitState;
        }
      }
      if (state == kDigitState) {
        if (!isdigit(c)) {
          break;
        }
        char num = c - '0';
        ret = ret * 10 + num;
        if (is_negative && ret > 2147483648) {
          return -2147483648;
        }
        if (!is_negative && ret > 2147483647) {
          return 2147483647;
        }
      }
    }
    return is_negative ? (-1 * ret) : ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.myAtoi("42"), 42);
  ASSERT_EQ(s.myAtoi("3"), 3);
  ASSERT_EQ(s.myAtoi("   -42"), -42);
  ASSERT_EQ(s.myAtoi("4193 with words"), 4193);
  ASSERT_EQ(s.myAtoi("words and 987"), 0);
  ASSERT_EQ(s.myAtoi("-91283472332"), -2147483648);
  ASSERT_EQ(s.myAtoi("+1"), 1);
  ASSERT_EQ(s.myAtoi("+-12"), 0);
  return 0;
}
