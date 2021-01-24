/*
 * @lc app=leetcode id=441 lang=cpp
 *
 * [441] Arranging Coins
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int arrangeCoins(int n) {
    int64_t sum_k = 0;
    for (int k = 0; k <= n; k++) {
      sum_k += (int64_t)k;
      if (sum_k == n) {
        return k;
      } else if (sum_k > n) {
        return k - 1;
      }
    }
    return 0;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.arrangeCoins(0) == 0);
  assert(s.arrangeCoins(1) == 1);
  assert(s.arrangeCoins(6) == 3);
  assert(s.arrangeCoins(5) == 2);
  assert(s.arrangeCoins(8) == 3);
  assert(s.arrangeCoins(1804289383) == 60070);
  return 0;
}
