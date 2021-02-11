/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int fib(int n) {
    if (n == 0) {
      return 0;
    } else if (n == 1) {
      return 1;
    }
    return fib(n - 1) + fib(n - 2);
  }
};
// @lc code=end

int
main () {
  Solution s;
  assert(s.fib(0) == 0);
  assert(s.fib(1) == 1);
  assert(s.fib(2) == 1);
  assert(s.fib(3) == 2);
  assert(s.fib(4) == 3);
  assert(s.fib(5) == 5);
  return 0;
}
