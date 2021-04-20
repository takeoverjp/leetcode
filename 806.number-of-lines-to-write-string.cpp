/*
 * @lc app=leetcode id=806 lang=cpp
 *
 * [806] Number of Lines To Write String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string s) {
    int line = 1;
    int last_width = 0;
    for (const char c : s) {
      int w = widths[c - 'a'];
      if (last_width + w > 100) {
        line++;
        last_width = w;
      } else {
        last_width += w;
      }
    }
    // cout << "line = " << line << ", last_width = " << last_width << std::endl;
    return {line, last_width};
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> width;
  vector<int> exp;
  width = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
           10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  exp = {3, 60};
  assert(s.numberOfLines(width, "abcdefghijklmnopqrstuvwxyz") == exp);
  width = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
           10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
  exp = {2, 4};
  assert(s.numberOfLines(width, "bbbcccdddaaa") == exp);
  return 0;
}
