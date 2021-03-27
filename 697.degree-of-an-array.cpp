/*
 * @lc app=leetcode id=697 lang=cpp
 *
 * [697] Degree of an Array
 */
#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;


// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        struct num_t {
            int count;
            int start;
            int len;
        };
        const int size = nums.size();
        unordered_map<int, struct num_t>accum;
        for (int i = 0; i < size; i++) {
            const int num = nums[i];
            if (accum.count(num)) {
                accum[num].count++;
                accum[num].len = i - accum[num].start + 1;
            } else {
                accum[num].count = 1;
                accum[num].start = i;
                accum[num].len = 1;
            }
        }
        int max_count = INT_MIN;
        int ret = INT_MAX;
        for (const auto&ac : accum) {
            if (max_count < ac.second.count) {
                max_count = ac.second.count;
                ret = ac.second.len;
            } else if (max_count == ac.second.count) {
                ret = min(ret, ac.second.len);
            }
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> nums;
  nums = {49999};
  ASSERT_EQ(s.findShortestSubArray(nums), 1);
  nums = {0};
  ASSERT_EQ(s.findShortestSubArray(nums), 1);
  nums = {0,0};
  ASSERT_EQ(s.findShortestSubArray(nums), 2);
  nums = {1,2,2,3,1};
  ASSERT_EQ(s.findShortestSubArray(nums), 2);
  nums = {1,2,2,3,1,4,2};
  ASSERT_EQ(s.findShortestSubArray(nums), 6);
  return 0;
}
