/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int idx = 0;
    int slen = s.length();
    int tlen = t.length();
    for (int i = 0; i < slen; i++) {
      bool is_found = false;
      for (int j = idx; j < tlen; j++) {
        if (t[j] == s[i]) {
          is_found = true;
          idx = j + 1;
          break;
        }
      }
      if (!is_found) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.isSubsequence("", "abcde"));
  assert(!s.isSubsequence("abc", ""));
  assert(s.isSubsequence("ace", "abcde"));
  assert(!s.isSubsequence("aec", "abcde"));
  assert(s.isSubsequence("abc", "ahbgdc"));
  assert(!s.isSubsequence("axc", "ahbgdc"));
  assert(!s.isSubsequence("aaaaaa", "bbaaaa"));
  return 0;
}
