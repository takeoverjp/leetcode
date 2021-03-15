/*
 * @lc app=leetcode id=657 lang=cpp
 *
 * [657] Robot Return to Origin
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool judgeCircle(string moves) {
    int x = 0, y = 0;
    for (const char c : moves) {
      switch (c) {
        case 'U':
          y++;
          break;
        case 'D':
          y--;
          break;
        case 'L':
          x--;
          break;
        case 'R':
          x++;
          break;
      }
    }
    return x == 0 && y == 0;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.judgeCircle("UD"));
  assert(!s.judgeCircle("LL"));
  assert(!s.judgeCircle("RRDD"));
  assert(!s.judgeCircle("LDRRLRUULR"));
  return 0;
}
