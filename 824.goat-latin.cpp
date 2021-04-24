/*
 * @lc app=leetcode id=824 lang=cpp
 *
 * [824] Goat Latin
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string toGoatLatin(string S) {
    int start = 0;
    int len = S.length();
    std::string ret;
    int index = 1;
    for (int i = 0; i < len; i++) {
      const char c = S[i];
      if (isspace(c)) {
          ret += toGoatLatinWord(S.substr(start, i - start), index++) + " ";
          start = i + 1;
      } else if (i == len - 1) {
          ret += toGoatLatinWord(S.substr(start, i - start + 1), index++);
      }
    }
    return ret;
  }

 private:
  bool isVowel(const char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
  string toGoatLatinWord(const string& word, const int index) {
    if (word.length() == 0) {
      return word;
    }
    string ret;
    if (isVowel(word[0])) {
        ret += word + "m" + string(index + 1, 'a');
    } else {
        ret += word.substr(1, word.length()) + word[0] + "m" + string(index + 1, 'a');
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.toGoatLatin("I speak Goat Latin"),
            "Imaa peaksmaaa oatGmaaaa atinLmaaaaa");
  ASSERT_EQ(s.toGoatLatin("The quick brown fox jumped over the lazy dog"),
            "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa "
            "hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa");
  return 0;
}
