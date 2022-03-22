/*
 * @lc app=leetcode id=1903 lang=cpp
 *
 * [1903] Largest Odd Number in String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string largestOddNumber(string num) {
    int len = num.length();
    for (int i = 0; i < len; i++) {
      if ((num[len - i - 1] - '0') % 2) {
        return num.substr(0, len - i);
      }
    }
    return "";
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.largestOddNumber("52"), "5");
  ASSERT_EQ(s.largestOddNumber("4206"), "");
  ASSERT_EQ(s.largestOddNumber("35427"), "35427");
  return 0;
}
