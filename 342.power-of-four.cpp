/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isPowerOfFour(int n) {
    if (n == 1) {
      return true;
    }
    if ((n <= 0) || (n % 4)) {
      return false;
    }
    return isPowerOfFour(n / 4);
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.isPowerOfFour(0) == false);
  assert(s.isPowerOfFour(1) == true);
  assert(s.isPowerOfFour(4) == true);
  assert(s.isPowerOfFour(116) == false);
  assert(s.isPowerOfFour(16) == true);
  return 0;
}