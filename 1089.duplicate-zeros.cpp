/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    size_t size = arr.size();
    for (int i = 0; i < size; i++) {
      if (arr[i] != 0) {
        continue;
      }

      if (i == size - 1) {
        break;
      }
      for (int j = size - 1; j > i + 1; j--) {
        arr[j] = arr[j - 1];
      }
      arr[i + 1] = 0;
      i++;
    }
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr, exp;
  arr = {1, 0, 2, 3, 0, 4, 5, 0};
  exp = {1, 0, 0, 2, 3, 0, 0, 4};
  s.duplicateZeros(arr);
  ASSERT_EQ(arr, exp);
  arr = {1, 2, 3};
  exp = {1, 2, 3};
  s.duplicateZeros(arr);
  ASSERT_EQ(arr, exp);
  return 0;
}
