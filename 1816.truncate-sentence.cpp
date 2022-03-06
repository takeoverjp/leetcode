/*
 * @lc app=leetcode id=1816 lang=cpp
 *
 * [1816] Truncate Sentence
 */
#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string truncateSentence(string s, int k) {
    int len = s.length();
    int count = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == ' ') {
        count++;
        if (count >= k) {
          return s.substr(0, i);
        }
      }
    }
    return s;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.truncateSentence("Hello how are you Contestant", 4),
            "Hello how are you");
  ASSERT_EQ(s.truncateSentence("What is the solution to this problem", 4),
            "What is the solution");
  ASSERT_EQ(s.truncateSentence("chopper is not a tanuki", 5),
            "chopper is not a tanuki");
  return 0;
}
