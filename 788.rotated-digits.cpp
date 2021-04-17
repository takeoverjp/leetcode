/*
 * @lc app=leetcode id=788 lang=cpp
 *
 * [788] Rotated Digits
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int rotatedDigits(int N) {
    int ret = 0;
    for (int i = 2; i <= N; i++) {
      if (rotatedDigit(i)) {
        ret++;
      }
    }
    return ret;
  }

 private:
  int rotate(int N) {
    switch (N) {
      case 0:
      case 1:
      case 8:
        return N;
      case 2:
        return 5;
      case 5:
        return 2;
      case 6:
        return 9;
      case 9:
        return 6;
    }
    return -1;
  }
  bool rotatedDigit(int N) {
    int orig = N;
    int rotated = 0;
    int count = 0;
    while (N) {
      int tmp = rotate(N % 10);
      if (tmp < 0) {
        return false;
      }
      N /= 10;
      rotated += tmp * pow(10, count++);
    }
    return orig != rotated;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.rotatedDigits(2), 1);
  ASSERT_EQ(s.rotatedDigits(10), 4);
  ASSERT_EQ(s.rotatedDigits(19), s.rotatedDigits(10) + 4);
  ASSERT_EQ(s.rotatedDigits(29), s.rotatedDigits(19) + 7);
  ASSERT_EQ(s.rotatedDigits(857), 247);
  return 0;
}
