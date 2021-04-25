/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> largeGroupPositions(string s) {
    vector<vector<int>> ret;
    int len = s.length();
    char last = '\0';
    int count = 0;
    for (int i = 0; i < len; ++i) {
      if (s[i] == last) {
        count++;
        if (i == len - 1) {
          if (count >= 3) {
            ret.push_back({len - count, len - 1});
          }
          return ret;
        }
      } else {
        if (count >= 3) {
          ret.push_back({i - count, i - 1});
        }
        count = 1;
        last = s[i];
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  string str;
  vector<vector<int>> exp;
  str = "abbxxxxzzy";
  exp = {{3, 6}};
  assert(s.largeGroupPositions(str) == exp);
  str = "abc";
  exp = {};
  assert(s.largeGroupPositions(str) == exp);
  str = "a";
  exp = {};
  assert(s.largeGroupPositions(str) == exp);
  str = "aaa";
  exp = {{0, 2}};
  assert(s.largeGroupPositions(str) == exp);
  str = "aaabaaa";
  exp = {{0, 2}, {4, 6}};
  assert(s.largeGroupPositions(str) == exp);
  str = "abcdddeeeeaabbbcd";
  exp = {{3, 5}, {6, 9}, {12, 14}};
  assert(s.largeGroupPositions(str) == exp);
  str = "aba";
  exp = {};
  assert(s.largeGroupPositions(str) == exp);
  return 0;
}
