/*
 * @lc app=leetcode id=1332 lang=cpp
 *
 * [1332] Remove Palindromic Subsequences
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int removePalindromeSub(string s) {
    if (s == std::string(s.rbegin(), s.rend())) {
      return 1;
    }
    return 2;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.removePalindromeSub("ababa"), 1);
  ASSERT_EQ(s.removePalindromeSub("abb"), 2);
  ASSERT_EQ(s.removePalindromeSub("baabb"), 2);
  return 0;
}
