/*
 * @lc app=leetcode id=1588 lang=cpp
 *
 * [1588] Sum of All Odd Length Subarrays
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int sumOddLengthSubarrays(vector<int>& arr) {
    int ret = 0;
    int size = arr.size();
    for (int i = 0; i < size; i++) {
      ret += arr[i] * (((i + 1) * (size - i) + 1) / 2);
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {1, 4, 2, 5, 3};
  ASSERT_EQ(s.sumOddLengthSubarrays(arr), 58);
  arr = {1, 2};
  ASSERT_EQ(s.sumOddLengthSubarrays(arr), 3);
  arr = {10, 11, 12};
  ASSERT_EQ(s.sumOddLengthSubarrays(arr), 66);
  return 0;
}
