/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_set<int> numset1(nums1.begin(), nums1.end());
    std::vector<int> result;
    for (auto num : nums2) {
      if (numset1.erase(num)) {
        result.push_back(num);
      }
    }
    return result;
  }
};
// @lc code=end
