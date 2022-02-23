/*
 * @lc app=leetcode id=1763 lang=cpp
 *
 * [1763] Longest Nice Substring
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string longestNiceSubstring(string s) {
    int len = s.length();
    for (int l = len; l > 0; l--) {
      for (int start = 0; start + l <= len; start++) {
        bool uppers[26] = {false};
        bool lowers[26] = {false};
        for (int i = start; i < start + l; i++) {
          if (isupper(s[i])) {
            uppers[s[i] - 'A'] = true;
          } else {
            lowers[s[i] - 'a'] = true;
          }
        }
        if (memcmp(uppers, lowers, sizeof(uppers)) == 0) {
          return s.substr(start, l);
        }
      }
    }
    return "";
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.longestNiceSubstring("YazaAay"), "aAa");
  ASSERT_EQ(s.longestNiceSubstring("Bb"), "Bb");
  ASSERT_EQ(s.longestNiceSubstring("c"), "");
  return 0;
}
