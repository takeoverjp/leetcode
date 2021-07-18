/*
 * @lc app=leetcode id=720 lang=cpp
 *
 * [720] Longest Word in Dictionary
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string longestWord(vector<string>& words) {
    std::sort(words.begin(), words.end(), [](const auto& lhs, const auto& rhs) {
      int l = lhs.length();
      int r = rhs.length();
      if (l == r) {
        return lhs < rhs;
      }
      return l > r;
    });
    int size = words.size();
    for (int i = 0; i < size; i++) {
      const string& candidate = words[i];
      //   cout << candidate << endl;
      if (canBuiltOneChar(candidate, words, i + 1)) {
        return candidate;
      }
    }
    return "";
  }

 private:
  bool canBuiltOneChar(const std::string word, vector<string>& words,
                       int start) {
    int candidate_len = word.length();
    if (candidate_len == 1) {
      return true;
    }
    const int size = words.size();
    for (int i = start; i < size; i++) {
      int len = words[i].length();
      if (len == candidate_len) {
        continue;
      } else if (len == candidate_len - 1) {
        if (word.find(words[i]) == 0) {
          return canBuiltOneChar(words[i], words, i + 1);
        } else {
          continue;
        }
      } else {
        return false;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words;
  words = {"w", "wo", "wor", "worl", "world"};
  ASSERT_EQ(s.longestWord(words), "world");
  words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  ASSERT_EQ(s.longestWord(words), "apple");
  words = {"yo",  "ew",   "fc", "zrc", "yodn", "fcm",  "qm",
           "qmo", "fcmz", "z",  "ewq", "yod",  "ewqz", "y"};
  ASSERT_EQ(s.longestWord(words), "yodn");
  return 0;
}
