/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool areAlmostEqual(string s1, string s2) {
    if (s1 == s2) {
      return true;
    }
    int len = s1.length();
    int count = 0;
    char diff1 = '\0';
    char diff2 = '\0';
    for (int i = 0; i < len; i++) {
      if (s1[i] == s2[i]) {
        continue;
      }
      count++;
      if (count == 1) {
        diff1 = s1[i];
        diff2 = s2[i];
      } else if (count == 2) {
        if (diff1 != s2[i] || diff2 != s1[i]) {
          return false;
        }
      } else {
        return false;
      }
    }
    return count == 2;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.areAlmostEqual("bank", "kanb"), true);
  ASSERT_EQ(s.areAlmostEqual("attack", "defend"), false);
  ASSERT_EQ(s.areAlmostEqual("kelb", "kelb"), true);
  return 0;
}
