/*
 * @lc app=leetcode id=1374 lang=cpp
 *
 * [1374] Generate a String With Characters That Have Odd Counts
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string generateTheString(int n) {
    string ret;
    ret.resize(n, 'a');
    if (n % 2 == 0) {
      ret[0] = 'b';
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.generateTheString(4), "baaa");
  ASSERT_EQ(s.generateTheString(2), "ba");
  ASSERT_EQ(s.generateTheString(7), "aaaaaaa");
  return 0;
}
