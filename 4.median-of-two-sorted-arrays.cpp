/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    int size = size1 + size2;
    double ret;
    int index1 = 0;
    int index2 = 0;
    if (size % 2) {
      int med_index = size / 2;
      while (true) {
        int num;
        if (index2 >= size2 || (index1 < size1 && nums1[index1] < nums2[index2])) {
          num = nums1[index1++];
        } else {
          num = nums2[index2++];
        }

        if (index1 + index2 == med_index + 1) {
          return num;
        }
      }
    } else {
      int med_index = size / 2 - 1;
      while (true) {
        int num;
        if (index2 >= size2 || (index1 < size1 && nums1[index1] < nums2[index2])) {
          num = nums1[index1++];
        } else {
          num = nums2[index2++];
        }

        if (index1 + index2 == med_index + 1) {
          ret = num;
        } else if (index1 + index2 == med_index + 2) {
          return (ret + num) / 2.0f;
        }
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums1, nums2;
  nums1 = {1, 3};
  nums2 = {2};
  ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.0f);
  nums1 = {1, 2};
  nums2 = {3, 4};
  ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.5f);
  nums1 = {0, 0};
  nums2 = {0, 0};
  ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 0.0f);
  nums1 = {};
  nums2 = {1};
  ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 1.0f);
  nums1 = {2};
  nums2 = {};
  ASSERT_EQ(s.findMedianSortedArrays(nums1, nums2), 2.0f);
  return 0;
}
