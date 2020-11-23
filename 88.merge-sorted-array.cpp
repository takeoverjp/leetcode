/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;


// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = nums1.size() - 1; i >= 0; i--) {
            if (m == 0) {
                nums1[i] = nums2[n-1];
                n--;
                continue;
            }
            if (n == 0) {
                nums1[i] = nums1[m-1];
                m--;
                continue;
            }
            if (nums1[m-1] > nums2[n-1]) {
                nums1[i] = nums1[m-1];
                m--;
            } else {
                nums1[i] = nums2[n-1];
                n--;
            }
        }
    }
};
// @lc code=end

int
main () {
  Solution s;
  std::vector<int> nums1, nums2;
  nums1 = {};
  nums2 = {};
  s.merge(nums1, 0, nums2, 0);
  assert(nums1 == std::vector<int>());

  nums1 = {1, 2, 3, 0, 0, 0};
  nums2 = {2, 5, 6};
  s.merge(nums1, 3, nums2, 3);
  assert(nums1 == std::vector<int>({1, 2, 2, 3, 5, 6}));

  return 0;
}
