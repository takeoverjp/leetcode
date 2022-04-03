/*
 * @lc app=leetcode id=1967 lang=cpp
 *
 * [1967] Number of Strings That Appear as Substrings in Word
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numOfStrings(vector<string>& patterns, string word) {
    int ret = 0;
    for (const auto& pattern : patterns) {
      if (word.find(pattern) != string::npos) {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> patterns;
  patterns = {"a", "abc", "bc", "d"};
  ASSERT_EQ(s.numOfStrings(patterns, "abc"), 3);
  patterns = {"a", "b", "c"};
  ASSERT_EQ(s.numOfStrings(patterns, "aaaaabbbbb"), 2);
  return 0;
}
