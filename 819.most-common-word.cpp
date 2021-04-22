/*
 * @lc app=leetcode id=819 lang=cpp
 *
 * [819] Most Common Word
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    std::unordered_map<std::string, int> counts;
    int len = paragraph.length();
    int start = 0;
    for (int i = 0; i < len; i++) {
      const char c = paragraph[i];
      if (i == len - 1 || strchr("!?',;. ", c)) {
        int word_len = (strchr("!?',;. ", c)) ? (i - start) : (i - start + 1);
        std::string word = paragraph.substr(start, word_len);
        if (word.length() != 0) {
          std::transform(word.begin(), word.end(), word.begin(),
                         [](char c) { return tolower(c); });
          if (std::find(banned.begin(), banned.end(), word) == banned.end()) {
            if (counts.count(word) == 0) {
              counts[word] = 1;
            } else {
              counts[word]++;
            }
          }
        }
        // cout << word << ": " << counts[word] << endl;
        start = i + 1;
      }
    }
    int max_count = 0;
    string max_word;
    for (const auto& count : counts) {
      if (count.second > max_count) {
        max_count = count.second;
        max_word = count.first;
      }
    }
    return max_word;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> banned;
  banned = {"hit"};
  ASSERT_EQ(
      s.mostCommonWord(
          "Bob hit a ball, the hit BALL flew far after it was hit.", banned),
      "ball");
  banned = {};
  ASSERT_EQ(
      s.mostCommonWord(
          "Bob hit a ball, the hit BALL flew far after it was hit.", banned),
      "hit");
  banned = {};
  ASSERT_EQ(s.mostCommonWord("a.", banned), "a");
  banned = {};
  ASSERT_EQ(s.mostCommonWord("Bob", banned), "bob");
  return 0;
}
