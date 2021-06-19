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
    const vector<vector<char>> symbols = {
        {'I', 'V'},
        {'X', 'L'},
        {'C', 'D'},
        {'M', '.'},
    };
    int digit = 0;
    string ret;
    while (num) {
      string work_str;
      int work_val = num % 10;
      switch (work_val) {
        case 0:
          break;
        case 1:
        case 2:
        case 3:
          while (work_val--) {
            work_str += symbols[digit][0];
          }
          break;
        case 4:
          work_str += string({symbols[digit][0], symbols[digit][1]});
          break;
        case 5:
          work_str += symbols[digit][1];
          break;
        case 6:
        case 7:
        case 8:
          work_str += symbols[digit][1];
          work_val -= 5;
          while (work_val--) {
            work_str += symbols[digit][0];
          }
          break;
        case 9:
          work_str += string({symbols[digit][0], symbols[digit + 1][0]});
          break;
      }
      num /= 10;
      digit++;
      ret = work_str + ret;
    }
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
