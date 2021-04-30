/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int size = arr.size();
    for (int i = 1; i < size; i++) {
      if (arr[i - 1] > arr[i]) {
        return i - 1;
      }
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {0, 1, 0};
  ASSERT_EQ(s.peakIndexInMountainArray(arr), 1);
  arr = {0, 2, 1, 0};
  ASSERT_EQ(s.peakIndexInMountainArray(arr), 1);
  arr = {0, 10, 5, 2};
  ASSERT_EQ(s.peakIndexInMountainArray(arr), 1);
  arr = {3, 4, 5, 1};
  ASSERT_EQ(s.peakIndexInMountainArray(arr), 2);
  arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
  ASSERT_EQ(s.peakIndexInMountainArray(arr), 2);
  return 0;
}
