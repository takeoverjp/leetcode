/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool validPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
      if (s[left] == s[right]) {
        left++;
        right--;
        continue;
      }
      if (isPalindrome(s, left + 1, right)) {
        return true;
      }
      return isPalindrome(s, left, right - 1);
    }
    return true;
  }

 private:
  bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
      if (s[left] != s[right]) {
        return false;
      }
      left++;
      right--;
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.validPalindrome(""), true);
  ASSERT_EQ(s.validPalindrome("a"), true);
  ASSERT_EQ(s.validPalindrome("aba"), true);
  ASSERT_EQ(s.validPalindrome("abca"), true);
  ASSERT_EQ(s.validPalindrome("acba"), true);
  ASSERT_EQ(s.validPalindrome("abac"), true);
  ASSERT_EQ(s.validPalindrome("caba"), true);
  ASSERT_EQ(s.validPalindrome("cabad"), false);
  ASSERT_EQ(s.validPalindrome("eeccccbebaeeabebccceea"), false);
  ASSERT_EQ(s.validPalindrome("aguokepa"
                              "tgbnvfqm"
                              "gmlcupuu"
                              "fxoohdfp"
                              "gjdmysgv"
                              "hmvffcnq"
                              "xjjxqncf"
                              "fvmhvgsy"
                              "mdjgpfdh"
                              "ooxfuupu"
                              "culmgmqf"
                              "vnbgtape"
                              "kouga"),
            true);
  return 0;
}
