/*
 * @lc app=leetcode id=1619 lang=cpp
 *
 * [1619] Mean of Array After Removing Some Elements
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int size = arr.size();

    int sum = 0;
    for (int i = size / 20; i < size - size / 20; i++) {
      sum += arr[i];
    }
    return (double)sum / (double)(size * 9 / 10);
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3};
  ASSERT_EQ(s.trimMean(arr), 2.00000);
  arr = {6,2,7,5,1,2,0,3,10,2,5,0,5,5,0,8,7,6,8,0};
  ASSERT_EQ(s.trimMean(arr), 4.00000);
  arr = {6,0,7,0,7,5,7,8,3,4,0,7,8,1,6,8,1,1,2,4,8,1,9,5,4,3,8,5,10,8,6,6,1,0,6,10,8,2,3,4};
  ASSERT_EQ(s.trimMean(arr), 4.77778);
  return 0;
}
