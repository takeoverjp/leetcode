/*
 * @lc app=leetcode id=1200 lang=cpp
 *
 * [1200] Minimum Absolute Difference
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    std::sort(std::begin(arr), std::end(arr));
    int diff = INT_MAX;
    const int size = arr.size();
    for (int i = 1; i < size; i++) {
      diff = std::min(diff, arr[i] - arr[i - 1]);
    }
    vector<vector<int>> ret;
    for (int i = 1; i < size; i++) {
      if (arr[i] - arr[i - 1] != diff) {
        continue;
      }
      ret.push_back({arr[i - 1], arr[i]});
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  vector<vector<int>> exp;
  arr = {4, 2, 1, 3};
  exp = {{1, 2}, {2, 3}, {3, 4}};
  ASSERT_EQ(s.minimumAbsDifference(arr), exp);

  arr = {1, 3, 6, 10, 15};
  exp = {{1, 3}};
  ASSERT_EQ(s.minimumAbsDifference(arr), exp);
  return 0;
}
