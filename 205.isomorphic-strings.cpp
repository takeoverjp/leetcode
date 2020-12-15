/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    unordered_map<char, char> s2t;
    unordered_map<char, char> t2s;
    size_t len = s.length();
    for (size_t i = 0; i < len; i++) {
      if (s2t[s[i]]) {
        if (s2t[s[i]] != t[i]) {
          return false;
        }
      } else {
        s2t[s[i]] = t[i];
      }
      if (t2s[t[i]]) {
        if (t2s[t[i]] != s[i]) {
          return false;
        }
      } else {
        t2s[t[i]] = s[i];
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.isIsomorphic("egg", "add") == true);
  assert(s.isIsomorphic("foo", "bar") == false);
  assert(s.isIsomorphic("paper", "title") == true);
  assert(s.isIsomorphic("ab", "aa") == false);
  return 0;
}
