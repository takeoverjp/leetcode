/*
 * @lc app=leetcode id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> addToArrayForm(vector<int>& num, int k) {
    int k_size = 0;
    while (k) {
      k /= 10;
      k_size++;
    }
    int size = std::max<int>(num.size(), k_size);
    vector<int> ret(size + 1, 0);
    for (int i = 0; i < size; i++) {
      ret[size - i] += num[size - i - 1] + (k % 10);
      if (ret[size - i] >= 10) {
        ret[size - i] -= 10;
        ret[size - i - 1]++;
      }
      k /= 10;
    }
    if (ret[0] == 0) {
      ret.erase(ret.begin());
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> num, exp;
  num = {1, 2, 0, 0};
  exp = {1, 2, 3, 4};
  ASSERT_EQ(s.addToArrayForm(num, 34), exp);
  num = {0};
  exp = {0};
  ASSERT_EQ(s.addToArrayForm(num, 0), exp);
  num = {2, 7, 4};
  exp = {4, 5, 5};
  ASSERT_EQ(s.addToArrayForm(num, 181), exp);
  num = {2, 1, 5};
  exp = {1, 0, 2, 1};
  ASSERT_EQ(s.addToArrayForm(num, 806), exp);
  num = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
  exp = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  ASSERT_EQ(s.addToArrayForm(num, 1), exp);
  num = {3, 8, 0, 3, 0, 2, 7, 0, 7, 6, 4, 9, 9, 1, 7, 6, 6, 1, 6, 4};
  exp = {3, 8, 0, 3, 0, 2, 7, 0, 7, 6, 4, 9, 9, 1, 7, 6, 6, 8, 3, 4};
  ASSERT_EQ(s.addToArrayForm(num, 670), exp);

  return 0;
}
