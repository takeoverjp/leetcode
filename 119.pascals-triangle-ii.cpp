/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> ret;
    ret.push_back(1);
    for (int i = 0; i < rowIndex; i++) {
      int size = ret.size();
      for (int j = size - 1; j >= 1; j--) {
        ret[j] += ret[j - 1];
      }
      ret.push_back(1);
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> exp;
  exp = {1};
  assert(s.getRow(0) == exp);
  exp = {1, 1};
  assert(s.getRow(1) == exp);
  exp = {1, 2, 1};
  assert(s.getRow(2) == exp);
  exp = {1, 3, 3, 1};
  assert(s.getRow(3) == exp);
  exp = {1, 4, 6, 4, 1};
  assert(s.getRow(4) == exp);
  exp = {1, 5, 10, 10, 5, 1};
  assert(s.getRow(5) == exp);
  return 0;
}
