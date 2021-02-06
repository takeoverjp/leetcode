/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 private:
  bool isKeyboardRow(const string& word) {
    const string rows[] = {"qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJKL",
                         "zxcvbnmZXCVBNM"};
    for (const auto& row: rows) {
        bool is_match = true;
        for (const char c : word) {
            if (find(row.begin(), row.end(), c) == row.end()) {
                is_match = false;
                break;
            }
        }
        if (is_match) {
            return true;
        }
    }
    return false;
  }

 public:
  vector<string> findWords(vector<string>& words) {
    vector<string> ret;
    for (const auto& word : words) {
      if (isKeyboardRow(word)) {
        ret.push_back(word);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words, act, exp;

  words = {"omk"};
  exp = {};
  act = s.findWords(words);
  assert(act == exp);

  words = {"Hello", "Alaska", "Dad", "Peace"};
  exp = {"Alaska", "Dad"};
  act = s.findWords(words);
  assert(act == exp);

  words = {"adsdf", "sfd"};
  exp = {"adsdf", "sfd"};
  act = s.findWords(words);
  assert(act == exp);

  return 0;
}
