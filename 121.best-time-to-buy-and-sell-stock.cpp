/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int max_profit = 0;
    int min_price = INT_MAX;
    for (int price : prices) {
      min_price = min(min_price, price);
      max_profit = max(max_profit, (price - min_price));
    }

    return max_profit;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> vec;
  vec = {};
  assert(s.maxProfit(vec) == 0);
  vec = {1};
  assert(s.maxProfit(vec) == 0);
  vec = {7, 1, 5, 3, 6, 4};
  assert(s.maxProfit(vec) == 5);
  vec = {7, 6, 4, 3, 1};
  assert(s.maxProfit(vec) == 0);
  return 0;
}
