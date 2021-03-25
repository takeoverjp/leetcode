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
    int index = 0;
    while (index < len - 1) {
      const int step = isHit(s, index);
      if (!step) {
          ++index;
          continue;
      }
      index += step;
      count += step;
    }
    return count;
  }
  int isHit(const string& s, int start) {
    int len = s.length();
    if (start > len - 1) {
      return 0;
    }
    char first = s[start];
    int count = 1;
    for (int i = start + 1; i < len; i++) {
      if (s[i] == first) {
        count++;
        continue;
      }
      break;
    }
    if (start + count + count > len) {
      return 0;
    }
    for (int i = start + count; i < start + count + count; i++) {
      if (s[i] == first) {
        return 0;
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
