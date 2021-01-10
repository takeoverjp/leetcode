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
  bool isPerfectSquare(int num) { return (int)pow((int)sqrt(num), 2) == num; }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.isPerfectSquare(0));
  assert(s.isPerfectSquare(15) == false);
  assert(s.isPerfectSquare(16));
  assert(s.isPerfectSquare(17) == false);
  assert(s.isPerfectSquare(2) == false);
  assert(s.isPerfectSquare(1));
  return 0;
}
