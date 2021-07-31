/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countCharacters(vector<string>& words, string chars) {
    char counts[26] = {0};
    for (const auto c : chars) {
      counts[c - 'a']++;
    }
    int ret = 0;
    for (const auto& word : words) {
      char work[26];
      memcpy(work, counts, sizeof(counts));
      for (const auto c : word) {
        if (work[c - 'a']-- == 0) {
          //   cout << "NG: " << word << endl;
          goto NEXT_WORD;
        }
      }
      //   cout << "OK: " << word << endl;
      ret += word.length();

    NEXT_WORD:;
    }

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words;
  string chars;
  words = {"cat", "bt", "hat", "tree"};
  chars = "atach";
  ASSERT_EQ(s.countCharacters(words, chars), 6);
  words = {"hello", "world", "leetcode"};
  chars = "welldonehoneyr";
  ASSERT_EQ(s.countCharacters(words, chars), 10);
  return 0;
}
