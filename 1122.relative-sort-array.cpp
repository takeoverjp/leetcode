/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    std::unordered_map<int, int> val2idx;
    for (int i = 0; i < arr2.size(); i++) {
      val2idx[arr2[i]] = i;
    }
    std::sort(arr1.begin(), arr1.end(), [&val2idx](auto lhs, auto rhs) {
      if (val2idx.count(lhs) == 0) {
        if (val2idx.count(rhs) == 0) {
          // ascending order
          return lhs < rhs;
        } else {
          // need to swap
          return false;
        }
      } else {
        if (val2idx.count(rhs) == 0) {
          // no need to swap
          return true;
        } else {
          return val2idx[lhs] < val2idx[rhs];
        }
      }
    });
    return arr1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr1, arr2, exp;
  arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19};
  arr2 = {2, 1, 4, 3, 9, 6};
  exp = {2, 2, 2, 1, 4, 3, 3, 9, 6, 7, 19};
  ASSERT_EQ(s.relativeSortArray(arr1, arr2), exp);
  return 0;
}
