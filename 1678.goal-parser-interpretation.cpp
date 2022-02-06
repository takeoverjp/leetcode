/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string interpret(string command) {
    int len = command.length();
    string ret;
    ret.reserve(len);
    for (int i = 0; i < len; i++) {
      if (command[i] == '(') {
        if (command[i + 1] == ')') {
          ret += 'o';
          i++;
        } else {
          ret += "al";
          i += 3;
        }
      } else {
        ret += command[i];
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.interpret("G()(al)"), "Goal");
  ASSERT_EQ(s.interpret("G()()()()(al)"), "Gooooal");
  ASSERT_EQ(s.interpret("(al)G(al)()()G"), "alGalooG");
  return 0;
}
