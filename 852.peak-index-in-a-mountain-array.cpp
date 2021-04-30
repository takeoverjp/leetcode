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
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;
    while (true) {
      if ((arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1])) {
        return mid;
      }
      if (arr[mid - 1] < arr[mid]) {
          start = min(end, mid + 1);
          mid = min(size - 2, (start + end) / 2);
          continue;
      }
      if (arr[mid - 1] > arr[mid]) {
          end = max(start, mid - 1);
          mid = max(1, (start + end) / 2);
          continue;
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
  arr = {3, 5, 3, 2, 0};
  ASSERT_EQ(s.peakIndexInMountainArray(arr), 1);
  arr = {24, 69, 100, 99, 79, 78, 67, 36, 26, 19};
  ASSERT_EQ(s.peakIndexInMountainArray(arr), 2);
  return 0;
}
