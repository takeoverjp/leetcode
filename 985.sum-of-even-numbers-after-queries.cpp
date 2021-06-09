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
    int64_t sum = accumulate(nums.begin(), nums.end(), 0, [](int sum, int num) {
      return sum + (num % 2 == 0 ? num : 0);
    });
    vector<int> ret(queries.size());
    int i = 0;
    for (const auto& query : queries) {
      if (nums[query[1]] % 2 == 0) {
          sum -= nums[query[1]];
      }
      nums[query[1]] += query[0];
      if (nums[query[1]] % 2 == 0) {
          sum += nums[query[1]];
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
