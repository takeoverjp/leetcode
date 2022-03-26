/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countTriples(int n) {
    vector<bool> is_sq(n * n + 1);
    for (int i = 1; i <= n; i++) {
      is_sq[i * i] = true;
    }
    int ret = 0;
    for (int a = 1; a <= n; a++) {
      for (int b = a; a * a + b * b <= n * n; b++) {
        if (is_sq[a * a + b * b]) {
          ret += 2;
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.countTriples(5), 2);
  ASSERT_EQ(s.countTriples(10), 4);
  ASSERT_EQ(s.countTriples(18), 10);
  return 0;
}
