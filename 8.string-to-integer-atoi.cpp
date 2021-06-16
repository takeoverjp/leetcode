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
    bool is_negative = false;
    int64_t ret = 0;
    int i = 0;
    while (s[i] == ' ') {
      i++;
    }
    if (s[i] == '+') {
      i++;
    } else if (s[i] == '-') {
      is_negative = true;
      i++;
    }
    while (isdigit(s[i])) {
      char num = s[i++] - '0';
      ret = ret * 10 + num;
      if (is_negative) {
        if (ret - 1 > INT32_MAX) {
          return INT32_MIN;
        }
      } else {
        if (ret > INT32_MAX) {
          return INT32_MAX;
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
  ASSERT_EQ(s.myAtoi("-91283472332"), INT32_MIN);
  ASSERT_EQ(s.myAtoi("-2147483648"), -2147483648);
  ASSERT_EQ(s.myAtoi("+1"), 1);
  ASSERT_EQ(s.myAtoi("+-12"), 0);
  return 0;
}
