/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ret(digits);
    for (int i = digits.size()-1; i >= 0; i--) {
      if (ret[i] != 9) {
        ret[i]++;
        break;
      }
      ret[i] = 0;
      if (i == 0) {
        ret.emplace(ret.begin(), 1);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> digits;
  digits = {1, 2, 3};
  assert(s.plusOne(digits) == vector<int>({1, 2, 4}));
  digits = {4, 3, 2, 1};
  assert(s.plusOne(digits) == vector<int>({4, 3, 2, 2}));
  digits = {0};
  assert(s.plusOne(digits) == vector<int>({1}));
  digits = {0, 0};
  assert(s.plusOne(digits) == vector<int>({0, 1}));
  digits = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
  assert(s.plusOne(digits) == vector<int>({7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,7}));
  digits = {1, 3, 9, 9, 9, 9};
  assert(s.plusOne(digits) == vector<int>({1, 4, 0, 0, 0, 0}));
  digits = {9, 9, 9, 9};
  assert(s.plusOne(digits) == vector<int>({1, 0, 0, 0, 0}));
  return 0;
}
