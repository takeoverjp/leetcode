/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    char news[s.length() + 1];
    char newt[t.length() + 1];

    backspace(s, news);
    backspace(t, newt);

    return (strcmp(news, newt) == 0);
  }

 private:
  void backspace(const string& str, char* buf) {
    int len = str.length();
    int idx = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] == '#') {
        if (idx > 0) {
          buf[--idx] = '\0';
        }
      } else {
        buf[idx++] = str[i];
      }
    }
    buf[idx] = '\0';
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.backspaceCompare("ab#c", "ad#c"), true);
  ASSERT_EQ(s.backspaceCompare("ab##", "c#d#"), true);
  ASSERT_EQ(s.backspaceCompare("a##c", "#a#c"), true);
  ASSERT_EQ(s.backspaceCompare("a#c", "b"), false);
  return 0;
}
