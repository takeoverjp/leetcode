/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string restoreString(string s, vector<int>& indices) {
    std::unordered_map<int, char> map;
    int i = 0;
    for (const auto idx : indices) {
      map[idx] = s[i++];
    }
    int size = s.length();
    for (int i = 0; i < size; i++) {
      s[i] = map[i];
    }
    return s;
  }
};
// @lc code=end

int main() {
  Solution s;
  std::vector<int> indices;
  indices = {4, 5, 6, 7, 0, 2, 1, 3};
  ASSERT_EQ(s.restoreString("codeleet", indices), "leetcode");
  indices = {0, 1, 2};
  ASSERT_EQ(s.restoreString("abc", indices), "abc");
  indices = {3, 1, 4, 2, 0};
  ASSERT_EQ(s.restoreString("aiohn", indices), "nihao");
  indices = {4, 0, 2, 6, 7, 3, 1, 5};
  ASSERT_EQ(s.restoreString("aaiougrt", indices), "arigatou");
  return 0;
}
