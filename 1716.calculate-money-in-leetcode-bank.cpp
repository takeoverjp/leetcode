/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int totalMoney(int n) {
    int week_num = n / 7;
    int day_num = n % 7;
    int total = week_num * (28 + 28 + (week_num - 1) * 7) / 2;
    total += day_num * (week_num + 1 + week_num + day_num) / 2;
    return total;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.totalMoney(4), 10);
  ASSERT_EQ(s.totalMoney(10), 37);
  ASSERT_EQ(s.totalMoney(20), 96);
  return 0;
}
