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
    int len = digits.length();
    if (len == 0) {
      return ret;
    }
    char combi[len + 1];
    combi[len] = '\0';
    std::unordered_map<char, string> keymap = {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
    };

    switch (len) {
      case 1:
        for (const auto c : keymap[digits[0]]) {
          combi[0] = c;
          ret.push_back(combi);
        }
        break;
      case 2:
        for (const auto c0 : keymap[digits[0]]) {
          combi[0] = c0;
          for (const auto c1 : keymap[digits[1]]) {
            combi[1] = c1;
            ret.push_back(combi);
          }
        }
        break;
      case 3:
        for (const auto c0 : keymap[digits[0]]) {
          combi[0] = c0;
          for (const auto c1 : keymap[digits[1]]) {
            combi[1] = c1;
            for (const auto c2 : keymap[digits[2]]) {
              combi[2] = c2;
              ret.push_back(combi);
            }
          }
        }
        break;
      case 4:
        for (const auto c0 : keymap[digits[0]]) {
          combi[0] = c0;
          for (const auto c1 : keymap[digits[1]]) {
            combi[1] = c1;
            for (const auto c2 : keymap[digits[2]]) {
              combi[2] = c2;
              for (const auto c3 : keymap[digits[3]]) {
                combi[3] = c3;
                ret.push_back(combi);
              }
            }
          }
        }
        break;
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
