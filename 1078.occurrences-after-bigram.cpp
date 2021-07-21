/*
 * @lc app=leetcode id=1078 lang=cpp
 *
 * [1078] Occurrences After Bigram
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> findOcurrences(string text, string first, string second) {
    vector<string> ret;
    vector<string> words;
    std::size_t pos = 0;
    std::size_t len = text.length();
    while (pos < len) {
      size_t ret = text.find(' ', pos);
      if (ret == std::string::npos) {
        words.push_back(text.substr(pos, len - pos));
        break;
      }
      words.push_back(text.substr(pos, ret - pos));
      pos = ret + 1;
    }

    for (size_t i = 0; i + 2 < words.size(); i++) {
    //   cout << "\"" << words[i] << "\"" << endl;
      if (words[i] == first && words[i + 1] == second) {
        ret.push_back(words[i + 2]);
      }
    }

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> exp;
  exp = {"girl", "student"};
  ASSERT_EQ(s.findOcurrences("alice is a good girl she is a good student", "a",
                             "good"),
            exp);
  exp = {"we", "rock"};
  ASSERT_EQ(s.findOcurrences("we will we will rock you", "we", "will"), exp);
  exp = {"we", "we", "rock"};
  ASSERT_EQ(s.findOcurrences("we we we we rock you", "we", "we"), exp);
  return 0;
}
