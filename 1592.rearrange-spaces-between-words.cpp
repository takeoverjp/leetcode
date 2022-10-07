/*
 * @lc app=leetcode id=1592 lang=cpp
 *
 * [1592] Rearrange Spaces Between Words
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string reorderSpaces(string text) {
    int spaces = 0;
    int words = 0;
    bool in_word = false;
    for (auto c : text) {
      if (isspace(c)) {
        spaces++;
        in_word = false;
      } else {
        if (!in_word) {
          in_word = true;
          words++;
        }
      }
    }
    int each_spaces = spaces / (words - 1);
    int last_spaces = spaces % (words - 1);
    string ret;
    ret.reserve(text.size());
    in_word = false;
    for (auto c : text) {
      if (isspace(c)) {
        in_word = false;
        continue;
      }
      if (!in_word) {
        in_word = true;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.reorderSpaces("  this   is  a sentence "),
            "this   is   a   sentence");
  ASSERT_EQ(s.reorderSpaces(" practice   makes   perfect"),
            "practice   makes   perfect ");
  return 0;
}
