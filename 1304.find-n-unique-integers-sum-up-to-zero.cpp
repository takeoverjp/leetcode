/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> ret;
    ret.resize(n);
    int index = 0;
    if (n % 2) {
      ret[0] = 0;
      index++;
    }
    int num = 1;
    for (; index < n; index++) {
      ret[index] = num;
      if (num > 0) {
        num = -1 * num;
      } else {
        num = -1 * num + 1;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> exp;
  exp = {0, 1, -1, 2, -2};
  ASSERT_EQ(s.sumZero(5), exp);
  exp = {0, 1, -1};
  ASSERT_EQ(s.sumZero(3), exp);
  exp = {0};
  ASSERT_EQ(s.sumZero(1), exp);
  return 0;
}
