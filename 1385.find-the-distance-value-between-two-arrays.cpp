/*
 * @lc app=leetcode id=1385 lang=cpp
 *
 * [1385] Find the Distance Value Between Two Arrays
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    return std::count_if(std::begin(arr1), std::end(arr1),
                         [&arr2, d](auto val) {
                           for (const auto num : arr2) {
                             if (abs(num - val) <= d) {
                               return false;
                             }
                           }
                           return true;
                         });
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr1, arr2;
  arr1 = {4, 5, 8};
  arr2 = {10, 9, 1, 8};
  ASSERT_EQ(s.findTheDistanceValue(arr1, arr2, 2), 2);
  arr1 = {1, 4, 2, 3};
  arr2 = {-4, -3, 6, 10, 20, 30};
  ASSERT_EQ(s.findTheDistanceValue(arr1, arr2, 3), 2);
  arr1 = {2, 1, 100, 3};
  arr2 = {-5, -2, 10, -3, 7};
  ASSERT_EQ(s.findTheDistanceValue(arr1, arr2, 6), 1);
  return 0;
}
