/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> shortestToChar(string s, char c) {
    int len = s.length();
    vector<int> ret(len);
    vector<int> indices;
    for (int i = 0; i < len; i++) {
      if (s[i] == c) {
        indices.push_back(i);
      }
    }
    for (int i = 0; i < len; i++) {
      int distance = INT_MAX;
      for (int index : indices) {
        distance = min(distance, abs(index - i));
      }
      ret[i] = distance;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> exp;
  exp = {3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0};
  assert(s.shortestToChar("loveleetcode", 'e') == exp);
  exp = {3, 2, 1, 0};
  assert(s.shortestToChar("aaab", 'b') == exp);
  return 0;
}
