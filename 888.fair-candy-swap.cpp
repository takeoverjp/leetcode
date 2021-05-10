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
    int totalA = accumulate(A.begin(), A.end(), 0);
    int totalB = accumulate(B.begin(), B.end(), 0);
    int diff = (totalA - totalB) / 2;
    unordered_set<int> setB(B.begin(), B.end());
    for (int sizeA : A) {
        if (setB.count(sizeA - diff)) {
          return {sizeA, sizeA - diff};
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
