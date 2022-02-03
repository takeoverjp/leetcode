/*
 * @lc app=leetcode id=1662 lang=cpp
 *
 * [1662] Check If Two String Arrays are Equivalent
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
    int total1 = accumulate(
        begin(word1), end(word1), 0,
        [](int sum, const auto& word) { return sum + word.length(); });
    int total2 = accumulate(
        begin(word2), end(word2), 0,
        [](int sum, const auto& word) { return sum + word.length(); });
    if (total1 != total2) {
      return false;
    }
    int widx1 = 0, widx2 = 0, cidx1 = 0, cidx2 = 0;
    int len2 = word2[widx2].length();
    for (widx1 = 0; widx1 < word1.size(); widx1++) {
      int len1 = word1[widx1].length();
      for (cidx1 = 0; cidx1 < len1; cidx1++) {
        if (word1[widx1][cidx1] != word2[widx2][cidx2]) {
          return false;
        }
        cidx2++;
        if (cidx2 >= len2) {
          widx2++;
          if (widx2 >= word2.size()) {
            return true;
          }
          cidx2 = 0;
          len2 = word2[widx2].length();
        }
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> word1, word2;
  word1 = {"ab", "c"};
  word2 = {"a", "bc"};
  ASSERT_EQ(s.arrayStringsAreEqual(word1, word2), true);
  word1 = {"a", "cb"};
  word2 = {"ab", "c"};
  ASSERT_EQ(s.arrayStringsAreEqual(word1, word2), false);
  word1 = {"abc", "d", "defg"};
  word2 = {"abcddefg"};
  ASSERT_EQ(s.arrayStringsAreEqual(word1, word2), true);
  return 0;
}
