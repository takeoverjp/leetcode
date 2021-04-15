/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numJewelsInStones(string jewels, string stones) {
    int count = 0;
    for (const char jewel : jewels) {
      for (const char stone : stones) {
        if (stone == jewel) {
          count++;
        }
      }
    }
    return count;
  }
};
// @lc code=end

int main() {
  Solution s;
  std::string jewels, stones;
  jewels = "aA";
  stones = "aAAbbbb";
  ASSERT_EQ(s.numJewelsInStones(jewels, stones), 3);
  jewels = "z";
  stones = "ZZ";
  ASSERT_EQ(s.numJewelsInStones(jewels, stones), 0);
  return 0;
}
