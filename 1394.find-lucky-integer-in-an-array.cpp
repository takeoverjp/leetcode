/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findLucky(vector<int>& arr) {
    std::unordered_map<int, int> counts;
    for (const auto num : arr) {
      counts[num]++;
    }
    int ret = -1;
    for (const auto& pair : counts) {
      if (pair.first == pair.second) {
        ret = std::max(ret, pair.first);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {2, 2, 3, 4};
  ASSERT_EQ(s.findLucky(arr), 2);
  arr = {1, 2, 2, 3, 3, 3};
  ASSERT_EQ(s.findLucky(arr), 3);
  arr = {2, 2, 2, 3, 3};
  ASSERT_EQ(s.findLucky(arr), -1);
  arr = {5};
  ASSERT_EQ(s.findLucky(arr), -1);
  arr = {7, 7, 7, 7, 7, 7, 7};
  ASSERT_EQ(s.findLucky(arr), 7);
  return 0;
}
