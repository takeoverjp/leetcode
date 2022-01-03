/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Sub-arrays
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_multiset<int> tset(target.begin(), target.end());
    unordered_multiset<int> aset(arr.begin(), arr.end());
    return tset == aset;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> target, arr;
  target = {1, 2, 3, 4};
  arr = {2, 4, 1, 3};
  ASSERT_EQ(s.canBeEqual(target, arr), true);
  target = {7};
  arr = {7};
  ASSERT_EQ(s.canBeEqual(target, arr), true);
  target = {3, 7, 9};
  arr = {3, 7, 11};
  ASSERT_EQ(s.canBeEqual(target, arr), false);
  target = {1, 2, 2, 3};
  arr = {1, 1, 2, 3};
  ASSERT_EQ(s.canBeEqual(target, arr), false);
  return 0;
}
