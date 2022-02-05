/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int ret = 0;
    for (const auto& account : accounts) {
      ret = max(ret, accumulate(begin(account), end(account), 0));
    }
    return ret;
  }
};
// @lc code=end
