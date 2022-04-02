/*
 * @lc app=leetcode id=1961 lang=cpp
 *
 * [1961] Check If String Is a Prefix of Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isPrefixString(string s, vector<string>& words) {
    string prefix;
    prefix.reserve(s.length());
    for (const auto& word : words) {
      if (prefix.length() > s.length()) {
        return false;
      }
      prefix += word;
      if (prefix == s) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words;
  words = {"i", "love", "leetcode", "apples"};
  ASSERT_EQ(s.isPrefixString("iloveleetcode", words), true);
  words = {"apples", "i", "love", "leetcode"};
  ASSERT_EQ(s.isPrefixString("iloveleetcode", words), false);
  return 0;
}
