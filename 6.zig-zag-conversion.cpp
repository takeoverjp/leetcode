/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) {
      return s;
    }
    int len = s.length();
    string ret(s);
    int idx = 0;

    // first row
    for (int i = 0; i < len; i += (numRows - 1) * 2) {
      ret[idx++] = s[i];
    }

    // intermediate rows
    for (int row = 1; row < numRows - 1; row++) {
      bool is_down = true;
      for (int i = row; i < len;) {
        ret[idx++] = s[i];
        if (is_down) {
          i += (numRows - row - 1) * 2;
          is_down = false;
        } else {
          i += row * 2;
          is_down = true;
        }
      }
    }

    // final row
    for (int i = numRows - 1; i < len; i += (numRows - 1) * 2) {
      ret[idx++] = s[i];
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR");
  ASSERT_EQ(s.convert("PAYPALISHIRING", 4), "PINALSIGYAHRPI");
  return 0;
}
