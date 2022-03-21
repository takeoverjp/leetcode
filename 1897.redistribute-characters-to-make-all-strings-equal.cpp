/*
 * @lc app=leetcode id=1897 lang=cpp
 *
 * [1897] Redistribute Characters to Make All Strings Equal
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool makeEqual(vector<string>& words) {
    int count[26] = {0};
    for (const auto& word : words) {
      for (const auto c : word) {
        count[c - 'a']++;
      }
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] % words.size() != 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words;
  words = {"abc", "aabc", "bc"};
  ASSERT_EQ(s.makeEqual(words), true);
  words = {"ab", "a"};
  ASSERT_EQ(s.makeEqual(words), false);
  return 0;
}
