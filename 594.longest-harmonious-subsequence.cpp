/*
 * @lc app=leetcode id=594 lang=cpp
 *
 * [594] Longest Harmonious Subsequence
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;


// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        std::map<int,int> counts;
        for (const auto &num : nums) {
            counts[num]++;
        }

        int ret = 0;
        for (auto it = counts.begin(); it != counts.end() && std::next(it) != counts.end(); ++it) {
            if (it->first + 1 != std::next(it)->first) {
                continue;
            }
            ret = std::max(ret, it->second + std::next(it)->second);
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  std::vector<int> nums;
  nums = {1,3,2,2,5,2,3,7};
  ASSERT_EQ(s.findLHS(nums), 5);
  nums = {1,2,3,4};
  ASSERT_EQ(s.findLHS(nums), 2);
  nums = {1,1,1,1};
  ASSERT_EQ(s.findLHS(nums), 0);
  nums = {1};
  ASSERT_EQ(s.findLHS(nums), 0);
  return 0;
}
