/*
 * @lc app=leetcode id=884 lang=cpp
 *
 * [884] Uncommon Words from Two Sentences
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> uncommonFromSentences(string A, string B) {
    unordered_map<string, int> uncommon;
    countUncommon(A, uncommon);
    countUncommon(B, uncommon);
    vector<string> ret;
    for (auto& pair : uncommon) {
      if (pair.second == 1) {
        ret.push_back(pair.first);
      }
    }
#if 0
    for (auto& word : ret) {
      cout << "@@@ \"" << word << "\"" << endl;
    }
#endif
    return ret;
  }

 private:
  void countUncommon(const string& s, unordered_map<string, int>& uncommon) {
    int len = s.length();
    int last = 0;
    for (int i = 0; i < len; i++) {
      string word;
      if (s[i] == ' ') {
        word = s.substr(last, i - last);
      } else if (i == len - 1) {
        word = s.substr(last, i - last + 1);
      }

      if (word.empty()) {
        continue;
      }

      if (uncommon.count(word)) {
        uncommon[word]++;
      } else {
        uncommon[word] = 1;
      }
      last = i + 1;
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> exp;

  // Example 1
  exp = {"sour", "sweet"};
  ASSERT_EQ(s.uncommonFromSentences("this apple is sweet",
                                    "this apple is sour") == exp,
            true);

  // Example 2
  exp = {"banana"};
  ASSERT_EQ(s.uncommonFromSentences("apple apple", "banana") == exp, true);

  return 0;
}
