/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    int i = 0;
    while (1) {
      uint64_t square = (uint64_t)i * (uint64_t)i;
      if (square < (uint)x) {
        i++;
        continue;
      }
      if (square == (uint)x) {
        return i;
      }
      return i - 1;
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.mySqrt(0) == 0);
  assert(s.mySqrt(4) == 2);
  assert(s.mySqrt(8) == 2);
  assert(s.mySqrt(9) == 3);
  assert(s.mySqrt(10) == 3);
  assert(s.mySqrt(2147483647) == 46340);
  return 0;
}
