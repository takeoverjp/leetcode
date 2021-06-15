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
    int ret = 0;
    for (const char c : s) {
      if (isspace(c)) {
        continue;
      }
      if (c == '-') {
        is_negative = true;
        continue;
      }
      char num = c - '0';
      ret = ret * 10 + num;
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
  return 0;
}
