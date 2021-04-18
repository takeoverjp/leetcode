/*
 * @lc app=leetcode id=796 lang=cpp
 *
 * [796] Rotate String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool rotateString(string A, string B) {
    int len = A.length();
    if (len != B.length()) {
      return false;
    }
    if (len == 0) {
        return true;
    }
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < len; j++) {
        if (A[j] != B[(i + j) % len]) {
          goto NEXT_LOOP;
        }
      }
      return true;

    NEXT_LOOP:;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.rotateString("", ""), true);
  ASSERT_EQ(s.rotateString("abcde", "cdeab"), true);
  ASSERT_EQ(s.rotateString("abcde", "abced"), false);
  return 0;
}
