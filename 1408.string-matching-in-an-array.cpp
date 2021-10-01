/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    int size = words.size();
    unordered_set<string> ret;
    for (int i = 0; i < size - 1; i++) {
      for (int j = i + 1; j < size; j++) {
        if (words[i].length() > words[j].length()) {
          if (words[i].find(words[j]) == std::string::npos) {
            continue;
          }
          ret.emplace(words[j]);
        } else {
          if (words[j].find(words[i]) == std::string::npos) {
            continue;
          }
          ret.emplace(words[i]);
        }
      }
    }
    return {ret.begin(), ret.end()};
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words, exp;
  words = {"mass", "as", "hero", "superhero"};
  exp = {"hero", "as"};
  ASSERT_EQ(s.stringMatching(words), exp);
  words = {"leetcode", "et", "code"};
  exp = {"code", "et"};
  ASSERT_EQ(s.stringMatching(words), exp);
  words = {"blue", "green", "bu"};
  exp = {};
  ASSERT_EQ(s.stringMatching(words), exp);
  words = {"leetcoder", "leetcode", "od", "hamlet", "am"};
  exp = {"am", "od", "leetcode"};
  ASSERT_EQ(s.stringMatching(words), exp);
  return 0;
}
