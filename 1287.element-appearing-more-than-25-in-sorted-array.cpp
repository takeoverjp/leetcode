/*
 * @lc app=leetcode id=1287 lang=cpp
 *
 * [1287] Element Appearing More Than 25% In Sorted Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    int limit = arr.size() / 4 + 1;
    int last = -1;
    int count = 1;
    for (const auto num : arr) {
      if (last != num) {
        last = num;
        count = 1;
        continue;
      }
      if (++count >= limit) {
        return num;
      }
    }
    return arr[0];
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {1, 2, 2, 6, 6, 6, 6, 7, 10};
  ASSERT_EQ(s.findSpecialInteger(arr), 6);
  arr = {1, 1};
  ASSERT_EQ(s.findSpecialInteger(arr), 1);
  arr = {1};
  ASSERT_EQ(s.findSpecialInteger(arr), 1);
  arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12, 12};
  ASSERT_EQ(s.findSpecialInteger(arr), 12);
  return 0;
}
