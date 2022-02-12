/*
 * @lc app=leetcode id=1704 lang=cpp
 *
 * [1704] Determine if String Halves Are Alike
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool halvesAreAlike(string s) {
    int len = s.length();
    int count_a = 0, count_b = 0;
    for (int i = 0; i < len / 2; i++) {
      if (is_vowel(s[i])) {
        count_a++;
      }
    }
    for (int i = len / 2; i < len; i++) {
      if (is_vowel(s[i])) {
        count_b++;
      }
    }
    return count_a == count_b;
  }

 private:
  bool is_vowel(char c) {
    c = tolower(c);
    switch (c) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.halvesAreAlike("book"), true);
  ASSERT_EQ(s.halvesAreAlike("textbook"), false);
  return 0;
}
