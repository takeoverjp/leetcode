/*
 * @lc app=leetcode id=1652 lang=cpp
 *
 * [1652] Defuse the Bomb
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int size = code.size();
    vector<int> ret(size, 0);
    if (k == 0) {
      return ret;
    }
    if (k > 0) {
      for (int i = 0; i < k; i++) {
        ret[0] += code[(1 + i) % size];
      }
      for (int i = 1; i < size; i++) {
        ret[i] = ret[i - 1] - code[i] + code[(i + k) % size];
      }
      return ret;
    }
    for (int i = 0; i > k; i--) {
      ret[0] += code[(i - 1 + size) % size];
    }
    for (int i = 1; i < size; i++) {
      ret[i] = ret[i - 1] + code[i - 1] - code[(i - 1 + k + size) % size];
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> code, exp;
  code = {5, 7, 1, 4};
  exp = {12, 10, 16, 13};
  ASSERT_EQ(s.decrypt(code, 3), exp);
  code = {1, 2, 3, 4};
  exp = {0, 0, 0, 0};
  ASSERT_EQ(s.decrypt(code, 0), exp);
  code = {2, 4, 9, 3};
  exp = {12, 5, 6, 13};
  ASSERT_EQ(s.decrypt(code, -2), exp);
  return 0;
}
