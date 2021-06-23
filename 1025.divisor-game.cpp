/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool divisorGame(int n) { return n % 2 == 0; }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.divisorGame(2), true);
  ASSERT_EQ(s.divisorGame(3), false);
  return 0;
}
