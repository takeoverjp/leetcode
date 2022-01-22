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
    for (int len = 1; len <= arr.size(); len += 2) {
      for (int start = 0; start + len - 1 < arr.size(); start++) {
        int end = start + len - 1;
        for (int i = start; i <= end; i++) {
          ret += arr[i];
        }
      }
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
