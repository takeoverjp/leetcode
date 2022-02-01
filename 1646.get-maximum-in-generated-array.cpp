/*
 * @lc app=leetcode id=1646 lang=cpp
 *
 * [1646] Get Maximum in Generated Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int getMaximumGenerated(int n) {
    if (n == 0) {
      return 0;
    }
    vector<int> cache(n + 1, -1);
    cache[0] = 0;
    cache[1] = 1;
    int m = 0;
    for (int i = n; i >= 0; i--) {
      m = max(m, rec(i, cache));
    }
    return m;
  }
  int rec(int n, vector<int> &cache) {
    if (cache[n] >= 0) {
      return cache[n];
    }
    int ret = 0;
    if (n % 2 == 0) {
      ret = rec(n / 2, cache);
    } else {
      ret = rec(n / 2, cache) + rec(n / 2 + 1, cache);
    }
    cache[n] = ret;
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.getMaximumGenerated(7), 3);
  ASSERT_EQ(s.getMaximumGenerated(2), 1);
  ASSERT_EQ(s.getMaximumGenerated(3), 2);
  ASSERT_EQ(s.getMaximumGenerated(4), 2);
  return 0;
}
