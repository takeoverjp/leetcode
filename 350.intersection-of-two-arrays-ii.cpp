/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());
    vector<int> result;
    std::set_intersection(nums1.begin(), nums1.end(), nums2.begin(),
                          nums2.end(), std::inserter(result, result.begin()));
    return result;
  }
};
// @lc code=end
