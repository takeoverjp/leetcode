/*
 * @lc app=leetcode id=1534 lang=cpp
 *
 * [1534] Count Good Triplets
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    size_t size = arr.size();
    uint64_t ans = 0;
    for (int i = 0; i < size - 2; ++i) {
      for (int j = i + 1; j < size - 1; ++j) {
        if (abs(arr[i] - arr[j]) > a) continue;
        for (int k = j + 1; k < size; ++k) {
          if (abs(arr[j] - arr[k]) <= b && abs(arr[k] - arr[i]) <= c) ans++;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
