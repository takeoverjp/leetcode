/*
 * @lc app=leetcode id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkRecord(string s) {
    int abs_num = 0;
    int cont_late_num = 0;
    for (const char c : s) {
      if (c == 'L')
        cont_late_num++;
      else
        cont_late_num = 0;
      if (c == 'A') abs_num++;
      if (cont_late_num > 2) return false;
      if (abs_num > 1) return false;
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.checkRecord("PPALLP"));
  assert(!s.checkRecord("PPALLL"));
  assert(!s.checkRecord("PPALAL"));
  return 0;
}
