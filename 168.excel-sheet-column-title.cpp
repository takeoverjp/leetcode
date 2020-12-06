/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  string convertToTitle(int n) {
    std::string ret;
    while (n > 0) {
      ret = std::string{static_cast<char>('A' + ((n - 1) % 26))} + ret;
      n = (n - 1) / 26;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.convertToTitle(1) == "A");
  assert(s.convertToTitle(28) == "AB");
  assert(s.convertToTitle(701) == "ZY");
  return 0;
}
