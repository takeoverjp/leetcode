/*
 * @lc app=leetcode id=453 lang=cpp
 *
 * [453] Minimum Moves to Equal Array Elements
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_num = INT_MAX;
        for (const auto num : nums) {
            min_num = min(num, min_num);
        }
        int ret = 0;
        for (const auto num : nums) {
            ret += num - min_num;
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> nums;
  nums = vector<int>{1,2,3};
  assert(s.minMoves(nums) == 3);
  nums = vector<int>{1,2,3, 3};
  assert(s.minMoves(nums) == 5);
  return 0;
}
