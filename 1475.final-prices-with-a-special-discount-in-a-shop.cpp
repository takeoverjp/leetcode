/*
 * @lc app=leetcode id=1475 lang=cpp
 *
 * [1475] Final Prices With a Special Discount in a Shop
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> finalPrices(vector<int>& prices) {
    int size = prices.size();
    for (int i = 0; i < size; i++) {
      int discount = 0;
      for (int j = i + 1; j < size; j++) {
        if (prices[j] <= prices[i]) {
          discount = prices[j];
          break;
        }
      }
      prices[i] -= discount;
    }
    return prices;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> prices, exp;
  prices = {8, 4, 6, 2, 3};
  exp = {4, 2, 4, 2, 3};
  ASSERT_EQ(s.finalPrices(prices), exp);
  prices = {1, 2, 3, 4, 5};
  exp = {1, 2, 3, 4, 5};
  ASSERT_EQ(s.finalPrices(prices), exp);
  prices = {10, 1, 1, 6};
  exp = {9, 0, 1, 6};
  ASSERT_EQ(s.finalPrices(prices), exp);
  return 0;
}
