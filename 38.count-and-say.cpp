/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  string convert(string s) {
    string ret;
    int len = s.size();
    char c = '\0';
    int count = 0;
    for (int i = 0; i < len; i++) {
      if (c != s[i]) {
        if (count > 0) {
          ret += to_string(count);
          ret.push_back(c);
        }
        c = s[i];
        count = 1;
      } else {
        count++;
      }
    }
    ret += to_string(count);
    ret.push_back(c);
    return ret;
  }
  string countAndSay(int n) {
    if (n <= 1) {
      return "1";
    }
    return convert(countAndSay(n - 1));
  }
};
// @lc code=end

int main() {
  Solution s;
  assert("1" == s.countAndSay(1));
  assert("11" == s.countAndSay(2));
  assert("21" == s.countAndSay(3));
  assert("1211" == s.countAndSay(4));
  assert("111221" == s.countAndSay(5));
  assert("312211" == s.countAndSay(6));
}