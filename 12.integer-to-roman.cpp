/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    int thousands = num / 1000;
    int hundreds = num / 100 % 10;
    int tens = num / 10 % 10;
    int ones = num % 10;
    string ret;

#define DIGIT_TO_ROMAN(digit, sym1, sym2, sym3)           \
  do {                                                    \
    if (digit) {                                          \
      if (digit < 4) {                                    \
        ret += string(digit, sym1);                       \
      } else if (digit < 5) {                             \
        ret += string({sym1, sym2});                      \
      } else if (digit < 9) {                             \
        ret += string(1, sym2) + string(digit - 5, sym1); \
      } else {                                            \
        ret += string({sym1, sym3});                      \
      }                                                   \
    }                                                     \
  } while (0)

    DIGIT_TO_ROMAN(thousands, 'M', '-', '-');
    DIGIT_TO_ROMAN(hundreds, 'C', 'D', 'M');
    DIGIT_TO_ROMAN(tens, 'X', 'L', 'C');
    DIGIT_TO_ROMAN(ones, 'I', 'V', 'X');

#undef DIGIT_TO_ROMAN

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.intToRoman(3), "III");
  ASSERT_EQ(s.intToRoman(4), "IV");
  ASSERT_EQ(s.intToRoman(9), "IX");
  ASSERT_EQ(s.intToRoman(58), "LVIII");
  ASSERT_EQ(s.intToRoman(1994), "MCMXCIV");
  return 0;
}
