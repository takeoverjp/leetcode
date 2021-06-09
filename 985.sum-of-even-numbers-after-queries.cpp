/*
 * @lc app=leetcode id=985 lang=cpp
 *
 * [985] Sum of Even Numbers After Queries
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& nums,
                                  vector<vector<int>>& queries) {
    vector<int> ret(queries.size());
    int64_t sum = 0;
    for (const auto& num : nums) {
      if (num % 2 == 0) {
        sum += num;
      }
    }
    int i = 0;
    for (const auto& query : queries) {
      int before = nums[query[1]];
      nums[query[1]] += query[0];
      int after = nums[query[1]];
      if (query[0] % 2 == 0) {
        if (after % 2 == 0) {
          sum += query[0];
        }
      } else {
        if (after % 2 == 0) {
          sum += after;
        } else {
          sum -= before;
        }
      }
      ret[i++] = sum;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  vector<vector<int>> queries;
  nums = {1, 2, 3, 4};
  queries = {{1, 0}, {-3, 1}, {-4, 0}, {2, 3}};
  ASSERT_EQ(s.sumEvenAfterQueries(nums, queries), vector<int>({8, 6, 2, 4}));
  nums = {1};
  queries = {{4, 0}};
  ASSERT_EQ(s.sumEvenAfterQueries(nums, queries), vector<int>({0}));
  return 0;
}
