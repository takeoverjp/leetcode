/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int titleToNumber(string s) {
    const char* str = s.c_str();
    int len = s.size();
    int ret = 0;
    for (int i = 0; i < len; i++) {
      ret += (str[i] - 'A' + 1);
      if (i >= len - 1) {
        break;
      }
      ret *= 26;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.titleToNumber("A") == 1);
  assert(s.titleToNumber("AB") == 28);
  assert(s.titleToNumber("ZY") == 701);
  assert(s.titleToNumber("AAA") == 703);
  return 0;
}
