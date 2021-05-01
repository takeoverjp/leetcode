/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool buddyStrings(string a, string b) {
    int alen = a.length();
    int blen = b.length();
    if (alen != blen) {
      return false;
    }
    if (a == b) {
        int size = std::set<char>(a.begin(), a.end()).size();
        if (size != alen) {
            return true;
        }
        return false;
    }
    int firsta = -1;
    int firstb = -1;
    int seconda = -1;
    for (int i = 0; i < alen; i++) {
      if (a[i] != b[i]) {
        if (firsta < 0) {
          firsta = a[i];
          firstb = b[i];
        } else if (seconda < 0) {
          if (a[i] != firstb || b[i] != firsta) {
            return false;
          }
          seconda = a[i];
        } else {
          return false;
        }
      }
    }
    if (seconda < 0) {
      return false;
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.buddyStrings("ab", "a"), false);
  ASSERT_EQ(s.buddyStrings("ab", "ba"), true);
  ASSERT_EQ(s.buddyStrings("ab", "ab"), false);
  ASSERT_EQ(s.buddyStrings("aa", "aa"), true);
  ASSERT_EQ(s.buddyStrings("aaaaaaabc", "aaaaaaacb"), true);
  return 0;
}
