/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int size = arr.size();
    int diff = arr[1] - arr[0];
    for (int i = 2; i < size; i++) {
      if (arr[i] - arr[i - 1] != diff) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {3, 5, 1};
  ASSERT_EQ(s.canMakeArithmeticProgression(arr), true);
  arr = {1, 2, 4};
  ASSERT_EQ(s.canMakeArithmeticProgression(arr), false);
  return 0;
}
