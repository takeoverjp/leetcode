/*
 * @lc app=leetcode id=1217 lang=cpp
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int minCostToMoveChips(vector<int>& position) {
    int odd = 0;
    int even = 0;
    for (const auto num : position) {
      if (num % 2) {
        odd++;
      } else {
        even++;
      }
    }
    return std::min(odd, even);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> position;
  position = {1, 2, 3};
  ASSERT_EQ(s.minCostToMoveChips(position), 1);
  position = {2, 2, 2, 3, 3};
  ASSERT_EQ(s.minCostToMoveChips(position), 2);
  position = {1, 1000000000};
  ASSERT_EQ(s.minCostToMoveChips(position), 1);
  return 0;
}
