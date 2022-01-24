/*
 * @lc app=leetcode id=1576 lang=cpp
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string modifyString(string s) {
    int size = s.length();
    for (int i = 0; i < size; i++) {
      if (s[i] != '?') {
        continue;
      }
      for (int j = 0; j < 26; j++) {
        if ((i >= 1) && (s[i - 1] == ('a' + j))) {
          continue;
        }
        if ((i < size - 1) && (s[i + 1] == ('a' + j))) {
          continue;
        }
        s[i] = 'a' + j;
        break;
      }
    }
    return s;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.modifyString("?zs"), "azs");
  ASSERT_EQ(s.modifyString("ubv?w"), "ubvaw");
  ASSERT_EQ(s.modifyString("ubv?w?zs"), "ubvawazs");
  return 0;
}
