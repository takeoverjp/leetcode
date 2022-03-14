/*
 * @lc app=leetcode id=1859 lang=cpp
 *
 * [1859] Sorting the Sentence
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string sortSentence(string s) {
    int len = s.length();
    string strings[9];
    int start = 0;
    int count = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == ' ') {
        strings[s[i - 1] - '1'] = s.substr(start, i - 1 - start);
        start = i + 1;
        count++;
      }
    }
    strings[s[len - 1] - '1'] = s.substr(start, len - 1 - start);
    count++;

    string ret;
    for (int i = 0; i < count; i++) {
      ret += strings[i];
      if (i != count - 1) {
        ret += " ";
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.sortSentence("is2 sentence4 This1 a3"), "This is a sentence");
  ASSERT_EQ(s.sortSentence("Myself2 Me1 I4 and3"), "Me Myself and I");
  return 0;
}
