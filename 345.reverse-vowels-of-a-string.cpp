/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  string reverseVowels(string s) {
    int first = 0;
    int last = s.length() - 1;
    while (first < last) {
      bool is_first_found = false;
      bool is_last_found = false;
      for (int i = first; i <= last; i++) {
        if (isVowel(s[i])) {
          first = i;
          is_first_found = true;
          break;
        }
      }

      for (int i = last; i >= first; i--) {
        if (isVowel(s[i])) {
          last = i;
          is_last_found = true;
          break;
        }
      }

      if (!is_first_found || !is_last_found) {
          break;
      }

      const char tmp = s[first];
      s[first] = s[last];
      s[last] = tmp;

      first++;
      last--;
    }

    return s;
  }

 private:
  bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' ||
        c == 'E' || c == 'I' || c == 'O' || c == 'U') {
      return true;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.reverseVowels("hello") == "holle");
  assert(s.reverseVowels("leetcode") == "leotcede");
  assert(s.reverseVowels("") == "");
  assert(s.reverseVowels("ltcd") == "ltcd");
  assert(s.reverseVowels("aeiou") == "uoiea");
  assert(s.reverseVowels("HELLO") == "HOLLE");
  return 0;
}
