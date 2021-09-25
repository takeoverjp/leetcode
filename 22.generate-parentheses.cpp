/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ret;
    traverse("", 0, 0, n, ret);
    return ret;
  }

 private:
  void traverse(std::string current, int open, int close, int max,
                vector<string>& ret) {
    if (current.length() == max * 2) {
      ret.push_back(current);
    }
    if (open < max) {
      traverse(current + "(", open + 1, close, max, ret);
    }
    if (close < open) {
      traverse(current + ")", open, close + 1, max, ret);
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> exp;
  exp = {"((()))", "(()())", "(())()", "()(())", "()()()"};
  ASSERT_EQ(s.generateParenthesis(3), exp);
  exp = {"()"};
  ASSERT_EQ(s.generateParenthesis(1), exp);
  exp = {"(((())))", "((()()))", "((())())", "((()))()", "(()(()))",
         "(()()())", "(()())()", "(())(())", "(())()()", "()((()))",
         "()(()())", "()(())()", "()()(())", "()()()()"};
  ASSERT_EQ(s.generateParenthesis(4), exp);
  return 0;
}
