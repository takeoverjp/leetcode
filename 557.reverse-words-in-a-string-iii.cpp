/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    int len = s.length();
    std::string ret(s);
    for (int start = 0; start < len; start++) {
      int end = start;
      for (int i = start; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
          end = i;
          break;
        }
      }

      /* reverse [start:(end-1)] */
      for (int i = start; i < end; i++) {
        ret[i] = s[(end - 1) - (i - start)];
      }

      start = end;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.reverseWords("Let's take LeetCode contest"),
            "s'teL ekat edoCteeL tsetnoc");
  ASSERT_EQ(s.reverseWords("a"), "a");
  ASSERT_EQ(s.reverseWords(""), "");
  ASSERT_EQ(s.reverseWords("abc"), "cba");
  ASSERT_EQ(s.reverseWords("abc def"), "cba fed");
  return 0;
}
