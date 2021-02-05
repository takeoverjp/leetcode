/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ret;
    for (const auto num1 : nums1) {
      bool is_found = false, is_greater_found = false;
      for (const auto num2 : nums2) {
        if (is_found && (num2 > num1)) {
          is_greater_found = true;
          ret.push_back(num2);
          break;
        }
        if (num2 == num1) {
          is_found = true;
        }
      }
      if (!is_greater_found) {
        ret.push_back(-1);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> ret, nums1, nums2;

  nums1 = {4, 1, 2};
  nums2 = {1, 3, 4, 2};
  ret = s.nextGreaterElement(nums1, nums2);
  assert(ret[0] == -1);
  assert(ret[1] == 3);
  assert(ret[2] == -1);

  nums1 = {2, 4};
  nums2 = {1, 2, 3, 4};
  ret = s.nextGreaterElement(nums1, nums2);
  assert(ret[0] == 3);
  assert(ret[1] == -1);

  nums1 = {2};
  nums2 = {1, 2, 3, 4};
  ret = s.nextGreaterElement(nums1, nums2);
  assert(ret[0] == 3);

  nums1 = {2};
  nums2 = {2};
  ret = s.nextGreaterElement(nums1, nums2);
  assert(ret[0] == -1);
  return 0;
}
