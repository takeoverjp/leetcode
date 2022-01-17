/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int ret = 0;
    int index = 0;
    while (k) {
      ret++;
      if (index < arr.size() && arr[index] == ret) {
        index++;
      } else {
        k--;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {2, 3, 4, 7, 11};
  ASSERT_EQ(s.findKthPositive(arr, 5), 9);
  arr = {1, 2, 3, 4};
  ASSERT_EQ(s.findKthPositive(arr, 2), 6);
  return 0;
}
