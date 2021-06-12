/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& words) {
    int size = words.size();
    char count[26][size];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < size; i++) {
      const string& word = words[i];
      for (const auto c : word) {
        count[c - 'a'][i]++;
      }
    }
    vector<string> ret;
    for (char c = 'a'; c <= 'z'; c++) {
      char count_min = CHAR_MAX;
      for (int i = 0; i < size; i++) {
        count_min = std::min(count_min, count[c - 'a'][i]);
      }
      for (int i = 0; i < count_min; i++) {
        ret.push_back(std::string() + c);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words, exp;
  words = {"bella", "label", "roller"};
  exp = {"e", "l", "l"};
  ASSERT_EQ(s.commonChars(words), exp);
  words = {"cool", "lock", "cook"};
  exp = {"c", "o"};
  ASSERT_EQ(s.commonChars(words), exp);
  return 0;
}
