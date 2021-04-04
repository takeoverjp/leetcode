/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string toLowerCase(string str) {
    for (char& c : str) {
      if (c >= 'A' && c <= 'Z') {
        c += 'a' - 'A';
      }
    }
    return str;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.toLowerCase("Hello"), "hello");
  ASSERT_EQ(s.toLowerCase("here"), "here");
  ASSERT_EQ(s.toLowerCase("LOVELY"), "lovely");
  ASSERT_EQ(s.toLowerCase("al&phaBET"), "al&phabet");
  return 0;
}
