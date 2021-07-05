/*
 * @lc app=leetcode id=1046 lang=cpp
 *
 * [1046] Last Stone Weight
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int lastStoneWeight(vector<int>& stones) {
    while (stones.size() > 1) {
      sort(stones.begin(), stones.end(),
           [](auto lhs, auto rhs) { return lhs > rhs; });

      int diff = stones[0] - stones[1];
      if (diff == 0) {
        stones.erase(stones.begin());
        stones.erase(stones.begin());
      } else {
        stones.erase(stones.begin());
        stones[0] = diff;
      }
    }

    return stones.size() ? stones[0] : 0;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> stones;
  stones = {2, 7, 4, 1, 8, 1};
  ASSERT_EQ(s.lastStoneWeight(stones), 1);
  return 0;
}
