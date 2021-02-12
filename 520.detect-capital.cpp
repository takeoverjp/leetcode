/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool detectCapitalUse(string word) {
      int len = word.length();
    if (islower(word[0])) {
      /* Case 2. leetcode */
      for (int i = 1; i < len; i++) {
        if (!islower(word[i])) {
          return false;
        }
      }
    } else { /* captal start */
      if (len <= 1) {
        return true;
      }
      if (islower(word[1])) {
        /* Case 3. Google */
        for (int i = 1; i < len; i++) {
          if (!islower(word[i])) {
            return false;
          }
        }
      } else {
        /* Case 1. USA */
        for (int i = 1; i < len; i++) {
          if (!isupper(word[i])) {
            return false;
          }
        }
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.detectCapitalUse("a"), true);
  ASSERT_EQ(s.detectCapitalUse("A"), true);
  ASSERT_EQ(s.detectCapitalUse("USA"), true);
  ASSERT_EQ(s.detectCapitalUse("Usa"), true);
  ASSERT_EQ(s.detectCapitalUse("usa"), true);
  ASSERT_EQ(s.detectCapitalUse("UsA"), false);
  ASSERT_EQ(s.detectCapitalUse("usA"), false);
  return 0;
}
