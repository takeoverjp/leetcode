/*
 * @lc app=leetcode id=1957 lang=cpp
 *
 * [1957] Delete Characters to Make Fancy String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string makeFancyString(string s) {
    string ret;
    ret.reserve(s.length());

    char last = '\0';
    int count = 0;
    for (const auto c : s) {
      if (last == c) {
        count++;
      } else {
        last = c;
        count = 1;
      }
      if (count <= 2) {
        ret += c;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.makeFancyString("leeetcode"), "leetcode");
  ASSERT_EQ(s.makeFancyString("aaabaaaa"), "aabaa");
  ASSERT_EQ(s.makeFancyString("aab"), "aab");
  return 0;
}
