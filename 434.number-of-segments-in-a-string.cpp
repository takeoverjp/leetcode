/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int countSegments(string s) {
    int count = 0;
    bool is_in_word = false;
    for (const auto c : s) {
      if (is_in_word && (c == ' ')) {
        is_in_word = false;
      }
      if (!is_in_word && (c != ' ')) {
        is_in_word = true;
        count++;
      }
    }
    return count;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.countSegments("Hello, my name is John") == 5);
  assert(s.countSegments("") == 0);
  assert(s.countSegments("                ") == 0);
  assert(s.countSegments("Hello") == 1);
  assert(s.countSegments("love live!") == 2);
  assert(s.countSegments("love live!") == 2);
  return 0;
}
