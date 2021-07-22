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
    int zero_num = std::count(arr.begin(), arr.end(), 0);
    int new_size = size + zero_num;
    for (int org_idx = size - 1, new_idx = new_size - 1;
         org_idx >= 0 && new_idx >= 0; org_idx--, new_idx--) {
      if (arr[org_idx] != 0) {
        if (new_idx < size) {
          arr[new_idx] = arr[org_idx];
        }
      } else {
        if (new_idx < size) {
          arr[new_idx] = 0;
        }
        new_idx--;
        if (new_idx < size) {
          arr[new_idx] = 0;
        }
      }
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
