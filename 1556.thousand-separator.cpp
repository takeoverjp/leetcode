/*
 * @lc app=leetcode id=1556 lang=cpp
 *
 * [1556] Thousand Separator
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string thousandSeparator(int n) {
    if (n == 0) {
      return "0";
    }
    int digits = 0;
    int work = n;
    while (work) {
      work /= 10;
      digits++;
    }
    digits += (digits - 1) / 3;
    char *ret = static_cast<char *>(alloca(digits + 1));
    ret[digits] = '\0';
    int index = digits - 1;
    int count = 0;
    work = n;
    while(true) {
      ret[index] = ('0' + (work % 10));
      index--;
      work /= 10;
      if (!work) {
        return ret;
      }

      count++;
      if (count % 3 == 0) {
        ret[index] = ('.');
        index--;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.thousandSeparator(0), "0");
  ASSERT_EQ(s.thousandSeparator(987), "987");
  ASSERT_EQ(s.thousandSeparator(1234), "1.234");
  return 0;
}
