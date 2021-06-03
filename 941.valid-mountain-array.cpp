/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool validMountainArray(vector<int>& arr) {
    enum { kFirst, kSecond, kIncreasing, kDecreasing } state = kFirst;
    int last = 0;
    for (int num : arr) {
      switch (state) {
        case kFirst:
          last = num;
          state = kSecond;
          break;
        case kSecond:
          if (num <= last) {
            return false;
          }
          last = num;
          state = kIncreasing;
          break;
        case kIncreasing:
          if (num == last) {
            return false;
          } else if (num < last) {
            last = num;
            state = kDecreasing;
            continue;
          } else {
            last = num;
            continue;
          }
          break;
        case kDecreasing:
          if (num >= last) {
            return false;
          }
          last = num;
          break;
      }
    }
    return state == kDecreasing;
  }
};
// @lc code=end
int main() {
  Solution s;
  vector<int> num;
  num = {2, 1};
  ASSERT_EQ(s.validMountainArray(num), false);
  num = {3, 5, 5};
  ASSERT_EQ(s.validMountainArray(num), false);
  num = {0, 3, 2, 1};
  ASSERT_EQ(s.validMountainArray(num), true);
  return 0;
}
