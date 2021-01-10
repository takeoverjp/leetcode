/*
 * @lc app=leetcode id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isPerfectSquare2(int num) { return (int)pow((int)sqrt(num), 2) == num; }
  bool isPerfectSquare(int num) {
    if (num == 1) {
      return true;
    }
    int start = 1;
    int end = num;
    while (start <= end) {
      int64_t candidate = ((int64_t)start + (int64_t)end) / 2;
      int64_t sqr = candidate * candidate;
      if (sqr == num) {
        return true;
      }
      if (sqr > num) {
        end = candidate - 1;
        candidate = (start + candidate) / 2;
      } else {
        start = candidate + 1;
        candidate = (end + candidate) / 2;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.isPerfectSquare(64516));
  assert(s.isPerfectSquare(2000105819) == false);
  assert(s.isPerfectSquare(9));
  assert(s.isPerfectSquare(15) == false);
  assert(s.isPerfectSquare(16));
  assert(s.isPerfectSquare(17) == false);
  assert(s.isPerfectSquare(2) == false);
  assert(s.isPerfectSquare(1));
  return 0;
}
