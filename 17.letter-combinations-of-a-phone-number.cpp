/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (digits.length() == 0) {
      return ret;
    }
    std::unordered_map<char, string> keymap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };
    ret.push_back("");

    for (auto digit : digits) {
      vector<string> tmp;

      for (const auto c : keymap[digit]) {
        for (const auto s : ret) {
          tmp.push_back(s + c);
        }
      }

      ret.swap(tmp);
    }

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> exp;
  exp = {};
  ASSERT_EQ(s.letterCombinations(""), exp);
  exp = {"a", "b", "c"};
  ASSERT_EQ(s.letterCombinations("2"), exp);
  exp = {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};
  ASSERT_EQ(s.letterCombinations("23"), exp);
  exp = {"ap", "aq", "ar", "as", "bp", "bq",
         "br", "bs", "cp", "cq", "cr", "cs"};
  ASSERT_EQ(s.letterCombinations("27"), exp);
  return 0;
}
