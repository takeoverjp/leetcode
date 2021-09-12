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
    return (n % 2) ? string(n, 'a') : (string(n - 1, 'a') + 'b');
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.generateTheString(4), "aaab");
  ASSERT_EQ(s.generateTheString(2), "ab");
  ASSERT_EQ(s.generateTheString(7), "aaaaaaa");
  return 0;
}
