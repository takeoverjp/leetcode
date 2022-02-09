/*
 * @lc app=leetcode id=1694 lang=cpp
 *
 * [1694] Reformat Phone Number
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string reformatNumber(string number) {
    string ret, work;
    work.reserve(number.size());
    ret.reserve(number.size());
    for (const char c : number) {
      if (isdigit(c)) {
        work += c;
      }
    }
    int len = work.length();
    int rest = len;
    int i = 0;
    for (i = 0; i < len - 4; i += 3) {
      ret += work[i];
      ret += work[i + 1];
      ret += work[i + 2];
      ret += '-';
      rest -= 3;
    }
    switch (rest) {
      case 4:
        ret += work[i++];
        ret += work[i++];
        ret += '-';
        ret += work[i++];
        ret += work[i++];
        break;
      case 3:
        ret += work[i++];
        ret += work[i++];
        ret += work[i++];
        break;
      case 2:
        ret += work[i++];
        ret += work[i++];
        break;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.reformatNumber("1-23-45 6"), "123-456");
  ASSERT_EQ(s.reformatNumber("123 4-567"), "123-45-67");
  ASSERT_EQ(s.reformatNumber("123 4-5678"), "123-456-78");
  return 0;
}
