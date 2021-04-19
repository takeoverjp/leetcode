/*
 * @lc app=leetcode id=804 lang=cpp
 *
 * [804] Unique Morse Code Words
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
static const vector<string> table_ = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};
class Solution {
 public:
  int uniqueMorseRepresentations(vector<string>& words) {
    std::set<string> morse_words;
    for (const auto& word : words) {
      morse_words.insert(morse(word));
    }
    return morse_words.size();
  }

 private:
  std::string morse(const std::string word) {
    std::string ret;
    for (const auto c : word) {
      ret += table_[c - 'a'];
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words;
  words = {"gin", "zen", "gig", "msg"};
  ASSERT_EQ(s.uniqueMorseRepresentations(words), 2);
  words = {""};
  ASSERT_EQ(s.uniqueMorseRepresentations(words), 1);
  words = {"", ""};
  ASSERT_EQ(s.uniqueMorseRepresentations(words), 1);
  return 0;
}
