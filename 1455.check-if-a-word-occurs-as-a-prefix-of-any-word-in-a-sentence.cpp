/*
 * @lc app=leetcode id=1455 lang=cpp
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int ret = 1;
    int index = 0;
    int size = searchWord.size();
    for (auto c : sentence) {
      if (c == ' ') {
        ret++;
        index = 0;
      } else if (index >= 0) {
        if (c == searchWord[index]) {
          index++;
          if (index >= size) {
            return ret;
          }
        } else {
          index = -1;
        }
      }
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.isPrefixOfWord("i love eating burger", "burg"), 4);
  ASSERT_EQ(s.isPrefixOfWord("this program is an easy problem", "pro"), 2);
  ASSERT_EQ(s.isPrefixOfWord("-1", "you"), -1);
  return 0;
}
