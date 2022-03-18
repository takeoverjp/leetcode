/*
 * @lc app=leetcode id=1880 lang=cpp
 *
 * [1880] Check if Word Equals Summation of Two Words
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    int first = 0, second = 0, target = 0;
    for (const auto c : firstWord) {
      first = first * 10 + (c - 'a');
    }
    for (const auto c : secondWord) {
      second = second * 10 + (c - 'a');
    }
    for (const auto c : targetWord) {
      target = target * 10 + (c - 'a');
    }
    return target == (first + second);
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.isSumEqual("acb", "cba", "cdb"), true);
  ASSERT_EQ(s.isSumEqual("aaa", "a", "aab"), false);
  ASSERT_EQ(s.isSumEqual("aaa", "a", "aaaa"), true);
  return 0;
}
