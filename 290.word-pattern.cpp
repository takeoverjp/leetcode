/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool wordPattern(string pattern, string s) {
    std::unordered_map<char, std::string> map;
    size_t index = 0;
    for (const char c : pattern) {
      if (index >= s.length()) {
        return false;
      }

      size_t next_index = s.find(' ', index);
      if (next_index == std::string::npos) {
        next_index = s.length();
      }
      const std::string word = s.substr(index, next_index - index);

      if (map.count(c)) {
        if (map[c] != word) {
          return false;
        }
      } else {
        for (const auto& pair : map) {
          if (pair.second == word) {
            return false;
          }
        }
        map[c] = word;
      }

      index = next_index + 1;
    }

    return index == s.length() + 1;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.wordPattern("abba", "dog cat cat dog"), true);
  ASSERT_EQ(s.wordPattern("abba", "dog cat cat fish"), false);
  ASSERT_EQ(s.wordPattern("aaaa", "dog cat cat dog"), false);
  ASSERT_EQ(s.wordPattern("abba", "dog dog dog dog"), false);
  ASSERT_EQ(s.wordPattern("aaaa", "dog dog dog dog"), true);
  ASSERT_EQ(s.wordPattern("aaa", "dog dog dog dog"), false);
  ASSERT_EQ(s.wordPattern("jquery", "jquery"), false);
  return 0;
}
