/*
 * @lc app=leetcode id=860 lang=cpp
 *
 * [860] Lemonade Change
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int coins[3] = {0, 0, 0};
    for (const int bill : bills) {
      switch (bill) {
        case 5:
          coins[0]++;
          break;
        case 10:
          if (coins[0] <= 0) {
            return false;
          }
          coins[0]--;
          coins[1]++;
          break;
        case 20:
          if (coins[0] > 0 && coins[1] > 0) {
            coins[0]--;
            coins[1]--;
            break;
          } else if (coins[0] >= 3) {
            coins[0] -= 3;
            break;
          } else {
            return false;
          }
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> bills;
  bills = {5, 5, 5, 10, 20};
  ASSERT_EQ(s.lemonadeChange(bills), true);
  bills = {5, 5, 10};
  ASSERT_EQ(s.lemonadeChange(bills), true);
  bills = {10, 10};
  ASSERT_EQ(s.lemonadeChange(bills), false);
  bills = {5, 5, 10, 10, 20};
  ASSERT_EQ(s.lemonadeChange(bills), false);
  bills = {5, 5, 10, 20, 5, 5, 5, 5, 5, 5, 5, 5, 5, 10, 5, 5, 20, 5, 20, 5};
  ASSERT_EQ(s.lemonadeChange(bills), true);
  return 0;
}
