/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string reverseStr(string s, int k) {
    int len = s.length();
    string ret(s);
    for (int start = 0; start < len; start += 2 * k) {
      int end = std::min(start + k, len) - 1;
      reverseStr(ret, start, end);
    }
    return ret;
  }

  private:
  void reverseStr(string& s, int start, int end) {
    for (int i = 0; i <= (end - start - 1) / 2; i++) {
      char tmp = s[end - i];
      s[end - i] = s[start + i];
      s[start + i] = tmp;
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.reverseStr("abc", 1), "abc");
  ASSERT_EQ(s.reverseStr("abc", 4), "cba");
  ASSERT_EQ(s.reverseStr("abcdefg", 4), "dcbaefg");
  ASSERT_EQ(s.reverseStr("abcdefg", 2), "bacdfeg");
  ASSERT_EQ(s.reverseStr("abcdefg", 1), "abcdefg");
  ASSERT_EQ(s.reverseStr("abc", 4), "cba");
  return 0;
}
