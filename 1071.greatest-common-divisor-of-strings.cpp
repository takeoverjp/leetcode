/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1 == str2) {
      return str1;
    }
    if (str1.length() == str2.length()) {
      return "";
    }
    if (str1.length() < str2.length()) {
      if (str2.find(str1) != 0) {
        return "";
      }
      return gcdOfStrings(
          str1, str2.substr(str1.length(), str2.length() - str1.length()));
    }
    if (str1.length() > str2.length()) {
      if (str1.find(str2) != 0) {
        return "";
      }
      return gcdOfStrings(
          str1.substr(str2.length(), str1.length() - str2.length()), str2);
    }
    return "";
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.gcdOfStrings("ABCABC", "ABC"), "ABC");
  ASSERT_EQ(s.gcdOfStrings("ABABAB", "ABAB"), "AB");
  ASSERT_EQ(s.gcdOfStrings("LEET", "CODE"), "");
  ASSERT_EQ(s.gcdOfStrings("ABCDEF", "ABC"), "");
  return 0;
}
