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
    std::set<int> numset1(nums1.begin(), nums1.end());
    std::set<int> numset2(nums2.begin(), nums2.end());
    std::vector<int> result;
    std::set_intersection(numset1.begin(), numset1.end(), numset2.begin(),
                          numset2.end(), std::inserter(result, result.end()));
    return result;
  }
};
// @lc code=end
