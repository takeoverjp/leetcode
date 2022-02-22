/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int minOperations(string s) {
    int count[2] = {0, 0};
    int len = s.length();
    for (int i = 0; i < len; i++) {
      if (i % 2) {
        if (s[i] == '0') {
          count[0]++;
        } else {
          count[1]++;
        }
      } else {
        if (s[i] == '0') {
          count[1]++;
        } else {
          count[0]++;
        }
      }
    }
    return min(count[0], count[1]);
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.minOperations("0100"), 1);
  ASSERT_EQ(s.minOperations("10"), 0);
  ASSERT_EQ(s.minOperations("1111"), 2);
  return 0;
}
