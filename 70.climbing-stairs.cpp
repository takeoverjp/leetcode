/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    int ret = 0;
    for (int num_two = 0; num_two <= n / 2; num_two++) {
      int num_one = n - 2 * num_two;
      int num = num_one + num_two;
      int min = std::min(num_one, num_two);
      uint64_t numerator = 1;
      uint64_t denominator = 1;
      for (int i = 0; i < min; i++) {
        numerator *= (num - i);
        denominator *= (i + 1);

        /* To avoid overflow */
        while ((numerator % 2 == 0) && (denominator % 2 == 0)) {
            numerator /= 2;
            denominator /= 2;
        }
      }
      uint64_t way = (numerator / denominator);
      ret += way;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.climbStairs(1) == 1);
  assert(s.climbStairs(2) == 2);
  assert(s.climbStairs(3) == 3);
  assert(s.climbStairs(4) == 5);
  assert(s.climbStairs(5) == 8);
  assert(s.climbStairs(6) == 13);
  assert(s.climbStairs(7) == 21);
  assert(s.climbStairs(8) == 34);
  assert(s.climbStairs(40) == 165580141);
  assert(s.climbStairs(44) == 1134903170);
  assert(s.climbStairs(45) == 1836311903);
  return 0;
}
