/*
 * @lc app=leetcode id=1518 lang=cpp
 *
 * [1518] Water Bottles
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    int ret = 0;
    int numEmptyBottles = 0;
    do {
      ret += numBottles;
      numEmptyBottles += numBottles;
      numBottles = numEmptyBottles / numExchange;
      numEmptyBottles %= numExchange;
    } while (numBottles);
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.numWaterBottles(9, 3), 13);
  ASSERT_EQ(s.numWaterBottles(15, 4), 19);
  return 0;
}
