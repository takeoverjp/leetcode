/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();
    int len = len1 + len2;
    string ret;
    ret.reserve(len);
    for (int i = 0; i < len; i++) {
      if (i / 2 >= len1) {
        ret += word2[i - len1];
      } else if (i / 2 >= len2) {
        ret += word1[i - len2];
      } else {
        if (i % 2 == 0) {
          ret += word1[i / 2];
        } else {
          ret += word2[i / 2];
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.mergeAlternately("abc", "pqr"), "apbqcr");
  ASSERT_EQ(s.mergeAlternately("ab", "pqrs"), "apbqrs");
  ASSERT_EQ(s.mergeAlternately("abcd", "pq"), "apbqcd");
  return 0;
}
