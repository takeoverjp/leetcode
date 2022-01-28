/*
 * @lc app=leetcode id=1624 lang=cpp
 *
 * [1624] Largest Substring Between Two Equal Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxLengthBetweenEqualCharacters(string s) {
    unordered_map<char, int> indexes;
    int ret = -1;
    for (int i = 0; i < s.size(); i++) {
      if (!indexes.count(s[i])) {
        indexes[s[i]] = i;
        continue;
      }

      ret = max(ret, i - indexes[s[i]] - 1);
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.maxLengthBetweenEqualCharacters("aa"), 0);
  ASSERT_EQ(s.maxLengthBetweenEqualCharacters("abca"), 2);
  ASSERT_EQ(s.maxLengthBetweenEqualCharacters("cbzxy"), -1);
  ASSERT_EQ(s.maxLengthBetweenEqualCharacters("mgntdygtxrvxjnwksqhxuxtrv"), 18);
  return 0;
}
