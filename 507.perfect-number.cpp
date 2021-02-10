/*
 * @lc app=leetcode id=507 lang=cpp
 *
 * [507] Perfect Number
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkPerfectNumber(int num) {
    if (num <= 1) {
      return false;
    }
    int sum = 1;
    int max = sqrt(num);
    for (int i = 2; i <= max; i++) {
      if (num % i == 0) {
        sum += i + (num / i);
      }
    }
    return sum == num;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.checkPerfectNumber(6));
  assert(s.checkPerfectNumber(28));
  assert(s.checkPerfectNumber(496));
  assert(s.checkPerfectNumber(8128));
  assert(!s.checkPerfectNumber(2));
  assert(!s.checkPerfectNumber(100000000));
  assert(!s.checkPerfectNumber(1));
  return 0;
}
