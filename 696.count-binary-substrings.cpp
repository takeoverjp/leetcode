/*
 * @lc app=leetcode id=696 lang=cpp
 *
 * [696] Count Binary Substrings
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countBinarySubstrings(string s) {
    int count = 0;
    const int len = s.length();
    int current_run_length = 1;
    int previous_run_length = 0;
    for (int i = 1; i < len; i++) {
      if (s[i] == s[i-1]) {
        ++current_run_length;
      } else {
        previous_run_length = current_run_length;
        current_run_length = 1;
      }
      if (previous_run_length >= current_run_length) {
        ++count;
      }
    }
    return count;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.isHit("00110011", 0), 2);
  ASSERT_EQ(s.isHit("00110011", 1), 1);
  ASSERT_EQ(s.isHit("00110011", 2), 2);
  ASSERT_EQ(s.isHit("00110011", 3), 1);
  ASSERT_EQ(s.isHit("00110011", 4), 2);
  ASSERT_EQ(s.isHit("00110011", 5), 1);
  ASSERT_EQ(s.isHit("00110011", 6), 0);
  ASSERT_EQ(s.isHit("00110011", 7), 0);
  ASSERT_EQ(s.countBinarySubstrings("00110011"), 6);
  ASSERT_EQ(s.countBinarySubstrings("10101"), 4);
  return 0;
}
