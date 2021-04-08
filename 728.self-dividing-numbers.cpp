/*
 * @lc app=leetcode id=728 lang=cpp
 *
 * [728] Self Dividing Numbers
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ret;
    for (int i = left; i <= right; i++) {
      if (selfDividingNumber(i)) {
        ret.push_back(i);
      }
    }
    return ret;
  }

 private:
  bool selfDividingNumber(int num) {
    if (num < 9) {
      return true;
    }

    int i = num;
    while (i) {
      if (i % 10 == 0) {
        return false;
      }
      if (num % (i % 10)) {
        return false;
      }
      i /= 10;
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> exp;
  exp = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22};
  assert(s.selfDividingNumbers(1, 22) == exp);
  exp = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  assert(s.selfDividingNumbers(1, 9) == exp);
  exp = {1};
  assert(s.selfDividingNumbers(1, 1) == exp);
  exp = {};
  assert(s.selfDividingNumbers(10000, 10000) == exp);
  return 0;
}
