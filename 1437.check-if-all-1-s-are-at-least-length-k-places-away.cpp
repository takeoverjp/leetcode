/*
 * @lc app=leetcode id=1437 lang=cpp
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int count = INT_MIN;
        for (auto num : nums) {
            if (num) {
                if (count >= 0 && count < k) {
                    return false;
                }
                count = 0;
            } else {
                count++;
            }
        }
        return true;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> nums;
  nums = {1,0,0,0,1,0,0,1};
  ASSERT_EQ(s.kLengthApart(nums, 2), true);
  nums = {1,0,0,0,1,0,1};
  ASSERT_EQ(s.kLengthApart(nums, 2), false);
  return 0;
}
