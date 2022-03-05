/*
 * @lc app=leetcode id=1812 lang=cpp
 *
 * [1812] Determine Color of a Chessboard Square
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool squareIsWhite(string coordinates) {
    return (coordinates[0] - 'a' + coordinates[1] - '1') % 2;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.squareIsWhite("a1"), false);
  ASSERT_EQ(s.squareIsWhite("h3"), true);
  ASSERT_EQ(s.squareIsWhite("c7"), false);
  return 0;
}
