/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int addDigits(int num) {
    if (!num) return num;
    return (num % 9) ? (num % 9) : 9;
  }
  int addDigitsNormal(int num) {
    while (num >= 10) {
      int val = num;
      int sum = 0;
      while (val) {
        sum += val % 10;
        val /= 10;
      }
      num = sum;
    }
    return num;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.addDigits(10) == 1);
  assert(s.addDigits(38) == 2);
  assert(s.addDigits(0) == 0);
  return 0;
}
