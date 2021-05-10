/*
 * @lc app=leetcode id=888 lang=cpp
 *
 * {888} Fair Candy Swap
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int totalA = 0, totalB = 0;
    for (int size : A) {
      totalA += size;
    }
    for (int size : B) {
      totalB += size;
    }
    int diff = (totalA - totalB);
    for (int sizeA : A) {
      for (int sizeB : B) {
        if ((sizeA - sizeB) * 2 == diff) {
          return {sizeA, sizeB};
        }
      }
    }
    return {-1, -1};
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> A = {1, 1}, B = {2, 2};
  vector<int> exp = {1, 2};
  ASSERT_EQ(s.fairCandySwap(A, B), exp);

  // Example 2:
  A = {1, 2}, B = {2, 3};
  exp = {1, 2};
  ASSERT_EQ(s.fairCandySwap(A, B), exp);

  // Example 3:
  A = {2}, B = {1, 3};
  exp = {2, 3};
  ASSERT_EQ(s.fairCandySwap(A, B), exp);

  // Example 4:
  A = {1, 2, 5}, B = {2, 4};
  exp = {5, 4};
  ASSERT_EQ(s.fairCandySwap(A, B), exp);

  return 0;
}
