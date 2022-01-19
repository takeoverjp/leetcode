/*
 * @lc app=leetcode id=1566 lang=cpp
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool containsPattern(vector<int>& arr, int m, int k) {
    for (int i = 0; i + m * k <= arr.size(); i++) {
      for (int j = 1; j < k; j++) {
        for (int l = 0; l < m; l++) {
          if (arr[i + l] != arr[i + m * j + l]) {
            goto NEXT_LOOP;
          }
        }
      }
      return true;
    NEXT_LOOP:;
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  int m, k;
  arr = {1, 2, 4, 4, 4, 4};
  m = 1;
  k = 3;
  ASSERT_EQ(s.containsPattern(arr, m, k), true);
  arr = {1, 2, 1, 2, 1, 1, 1, 3};
  m = 2;
  k = 2;
  ASSERT_EQ(s.containsPattern(arr, m, k), true);
  arr = {1, 2, 1, 2, 1, 3};
  m = 2;
  k = 3;
  ASSERT_EQ(s.containsPattern(arr, m, k), false);
  arr = {2, 2};
  m = 1;
  k = 2;
  ASSERT_EQ(s.containsPattern(arr, m, k), true);
  return 0;
}
