/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string shortestCompletingWord(string licensePlate, vector<string>& words) {
    int need[26];
    memset(need, 0, sizeof(need));
    for (const auto c : licensePlate) {
      if (isalpha(c)) {
        if (c >= 'A' && c <= 'Z') {
          need[c - 'A']++;
        } else {
          need[c - 'a']++;
        }
      }
    }

    // Use not std::sort but std::stable_sort, to preserve order for same length
    std::stable_sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
      return lhs.length() < rhs.length();
    });

    for (const auto& word : words) {
      int copy[26];
      memcpy(copy, need, sizeof(copy));
      if (isCompleting(copy, word)) {
        return word;
      }
    }
    return "";
  }

 private:
  bool isCompleting(int need[], const string& word) {
    for (const auto c : word) {
      need[c - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (need[i] > 0) {
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
  words = {"step", "steps", "stripe", "stepple"};
  ASSERT_EQ(s.shortestCompletingWord("1s3 PSt", words), "steps");
  words = {"looks", "pest", "stew", "show"};
  ASSERT_EQ(s.shortestCompletingWord("1s3 456", words), "pest");
  words = {"suggest",   "letter", "of",      "husband", "easy",
           "education", "drug",   "prevent", "writer",  "old"};
  ASSERT_EQ(s.shortestCompletingWord("Ah71752", words), "husband");
  words = {"enough", "these",  "play",  "wide", "wonder",
           "box",    "arrive", "money", "tax",  "thus"};
  ASSERT_EQ(s.shortestCompletingWord("OgEu755", words), "enough");
  words = {"claim", "consumer", "student", "camera",  "public",
           "never", "wonder",   "simple",  "thought", "use"};
  ASSERT_EQ(s.shortestCompletingWord("iMSlpe4", words), "simple");
  words = {"bad", "and"};
  ASSERT_EQ(s.shortestCompletingWord("Ad1234", words), "bad");
  return 0;
}
