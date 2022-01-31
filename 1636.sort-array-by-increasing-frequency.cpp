/*
 * @lc app=leetcode id=1636 lang=cpp
 *
 * [1636] Sort Array by Increasing Frequency
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> frequencySort(vector<int>& nums) {
    map<int, int> counts;
    for (const auto num : nums) {
      counts[num]++;
    }
    vector<pair<int, int>> vcounts;
    for (const auto& pair : counts) {
        vcounts.emplace_back(pair.first, pair.second);
    }

    sort(vcounts.begin(), vcounts.end(), [](const auto& lhs, const auto& rhs) {
      return (lhs.second == rhs.second) ? (lhs.first > rhs.first)
                                        : (lhs.second < rhs.second);
    });
    int index = 0;
    for (const auto& pair : vcounts) {
      for (int i = 0; i < pair.second; i++) {
        nums[index++] = pair.first;
      }
    }
    return nums;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {1, 1, 2, 2, 2, 3};
  exp = {3, 1, 1, 2, 2, 2};
  ASSERT_EQ(s.frequencySort(nums), exp);
  nums = {2, 3, 1, 3, 2};
  exp = {1, 3, 3, 2, 2};
  ASSERT_EQ(s.frequencySort(nums), exp);
  nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
  exp = {5, -1, 4, 4, -6, -6, 1, 1, 1};
  ASSERT_EQ(s.frequencySort(nums), exp);
  return 0;
}
