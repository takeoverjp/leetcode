/*
 * @lc app=leetcode id=521 lang=cpp
 *
 * [521] Longest Uncommon Subsequence I
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findLUSlength(string a, string b) {
    int alen = a.length();
    int blen = b.length();
    if (alen != blen) {
      return std::max(alen, blen);
    }
    return (a != b) ? alen : -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.findLUSlength("aba", "cdc"), 3);
  ASSERT_EQ(s.findLUSlength("aaa", "aab"), 3);
  ASSERT_EQ(s.findLUSlength("abc", "abd"), 3);
  ASSERT_EQ(s.findLUSlength("aaa", "bbb"), 3);
  ASSERT_EQ(s.findLUSlength("aaa", "aaa"), -1);
  ASSERT_EQ(s.findLUSlength("aefawfawfawfaw", "aefawfeawfwafwaef"), 17);
  return 0;
}
