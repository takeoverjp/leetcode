/*
 * @lc app=leetcode id=942 lang=cpp
 *
 * [942] DI String Match
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> diStringMatch(string s) {
    vector<int> ret;
    int start = 0;
    int end = s.length();
    for (const char c : s) {
      if (c == 'D') {
        ret.push_back(end--);
      } else {
        ret.push_back(start++);
      }
    }
    ret.push_back(end);
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> exp;
  exp = {0, 4, 1, 3, 2};
  ASSERT_EQ(s.diStringMatch("IDID"), exp);
  exp = {0, 1, 2, 3};
  ASSERT_EQ(s.diStringMatch("III"), exp);
  exp = {3, 2, 0, 1};
  ASSERT_EQ(s.diStringMatch("DDI"), exp);
  return 0;
}
