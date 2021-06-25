/*
 * @lc app=leetcode id=1021 lang=cpp
 *
 * [1021] Remove Outermost Parentheses
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string removeOuterParentheses(string s) {
    int index = 0;
    char ret[s.length() + 1];
    int depth = 0;
    for (const char c : s) {
      if (depth == 0) {
        depth++;
        continue;
      }
      depth += (c == '(') ? 1 : -1;
      if (depth == 0) {
        continue;
      }
      ret[index++] = c;
    }
    ret[index] = '\0';
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.removeOuterParentheses("(()())(())"), "()()()");
  ASSERT_EQ(s.removeOuterParentheses("(()())(())(()(()))"), "()()()()(())");
  ASSERT_EQ(s.removeOuterParentheses("()()"), "");
  return 0;
}
