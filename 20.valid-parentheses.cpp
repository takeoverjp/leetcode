/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <assert.h>

#include <stack>
#include <string>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    int len = s.length();
    stack<char> vec;
    for (int i = 0; i < len; i++) {
      switch (s[i]) {
        case '(':
        case '{':
        case '[':
          vec.push(s[i]);
          break;
        case ']':
          if (!vec.size()) return false;
          if (vec.top() != '[') return false;
          vec.pop();
          break;
        case '}':
          if (!vec.size()) return false;
          if (vec.top() != '{') return false;
          vec.pop();
          break;
        case ')':
          if (!vec.size()) return false;
          if (vec.top() != '(') return false;
          vec.pop();
          break;
        default:
          break;
      }
    }

    if (vec.size()) return false;
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(!s.isValid("("));
  assert(!s.isValid("]"));
  assert(s.isValid("()"));
  assert(s.isValid("()[]{}"));
  assert(!s.isValid("(]"));
  assert(!s.isValid("([)]"));
  assert(s.isValid("{[]}"));
}
