/*
 * @lc app=leetcode id=1945 lang=cpp
 *
 * [1945] Sum of Digits of String After Convert
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int getLucky(string s, int k) {
    int ret = 0;
    for (const auto c : s) {
      int num = c - 'a' + 1;
      ret += num % 10 + num / 10;
    }
    k--;

    for (int i = 0; i < k; i++) {
      int work = ret;
      ret = 0;
      while (work) {
        ret += work % 10;
        work /= 10;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.getLucky("iiii", 1), 36);
  ASSERT_EQ(s.getLucky("leetcode", 2), 6);
  ASSERT_EQ(s.getLucky("zbax", 2), 8);
  return 0;
}
