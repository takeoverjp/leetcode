/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */
#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    sort(begin(boxTypes), end(boxTypes),
         [](const auto& lhs, const auto& rhs) { return lhs[1] > rhs[1]; });
    int ret = 0;
    for (const auto& pair : boxTypes) {
      int box = min(truckSize, pair[0]);
      ret += box * pair[1];
      truckSize -= box;
      if (truckSize == 0) {
        break;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> boxTypes;
  boxTypes = {{1, 3}, {2, 2}, {3, 1}};
  ASSERT_EQ(s.maximumUnits(boxTypes, 4), 8);
  boxTypes = {{5, 10}, {2, 5}, {4, 7}, {3, 9}};
  ASSERT_EQ(s.maximumUnits(boxTypes, 10), 91);
  return 0;
}
