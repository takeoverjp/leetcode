/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input array is sorted
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int len = numbers.size();
    int i = 0;
    int j = 0;
    for (i = 0; i < len; i++) {
      int rest = target - numbers[i];
      auto it = lower_bound(numbers.begin()+i+1, numbers.end(), rest);
      if (it != numbers.end() && *it == rest) {
        j = distance(numbers.begin(), it);
        break;
      }
    }
    return {i + 1, j + 1};
  }
};
// @lc code=end
