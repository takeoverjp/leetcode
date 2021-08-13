/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ret;
    int size = nums.size();
    if (size < 4) {
      return ret;
    }
    std::sort(std::begin(nums), std::end(nums));

    for (int i = 0; i < size - 3; i++) {
      for (int j = i + 1; j < size - 2; j++) {
        int64_t rest = target - nums[i] - nums[j];
        int front = j + 1;
        int back = size - 1;
        while (front < back) {
          int64_t sum_front_back = nums[front] + nums[back];
          if (sum_front_back < rest) {
            front++;
            continue;
          }
          if (sum_front_back > rest) {
            back--;
            continue;
          }
          vector<int> arr{nums[i], nums[j], nums[front], nums[back]};
          ret.push_back(arr);

          // Skip duplicates
          while (front < back && nums[front] == arr[2]) {
            front++;
          }

          // Skip duplicates
          while (front < back && nums[back] == arr[3]) {
            back--;
          }
        }
        // Skip duplicates
        while (j + 1 < size - 2 && nums[j] == nums[j + 1]) {
          j++;
        }
      }
      // Skip duplicates
      while (i + 1 < size - 3 && nums[i] == nums[i + 1]) {
        i++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  vector<vector<int>> exp;
  nums = {2, 2, 2, 2, 2};
  exp = {{2, 2, 2, 2}};
  ASSERT_EQ(s.fourSum(nums, 8), exp);
  nums = {1, 0, -1, 0, -2, 2};
  exp = {{-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}};
  ASSERT_EQ(s.fourSum(nums, 0), exp);
  nums = {1000000000, 1000000000, 1000000000, 1000000000};
  exp = {};
  ASSERT_EQ(s.fourSum(nums, 0), exp);
  return 0;
}
