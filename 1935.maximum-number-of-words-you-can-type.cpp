/*
 * @lc app=leetcode id=1935 lang=cpp
 *
 * [1935] Maximum Number of Words You Can Type
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int canBeTypedWords(string text, string brokenLetters) {
    bool is_broken[26];
    memset(is_broken, 0, sizeof(is_broken));
    for (const auto c : brokenLetters) {
      is_broken[c - 'a'] = true;
    }
    bool is_broken_word = false;
    int ret = 0;
    for (const auto c : text) {
      if (c == ' ') {
        if (!is_broken_word) {
          ret++;
        }
        is_broken_word = false;
        continue;
      }
      if (is_broken_word) {
        continue;
      }
      if (is_broken[c - 'a']) {
        is_broken_word = true;
        continue;
      }
    }
    if (!is_broken_word) {
      ret++;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.canBeTypedWords("hello world", "ad"), 1);
  ASSERT_EQ(s.canBeTypedWords("leet code", "lt"), 1);
  ASSERT_EQ(s.canBeTypedWords("leet code", "e"), 0);
  return 0;
}
