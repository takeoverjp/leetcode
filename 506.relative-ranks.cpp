/*
 * @lc app=leetcode id=506 lang=cpp
 *
 * [506] Relative Ranks
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> findRelativeRanks(vector<int>& nums) {
    vector<pair<int, int>> pairs;
    int index = 0;
    for (const int num : nums) {
      pairs.push_back(make_pair(num, index));
      index++;
    }
    std::sort(
        pairs.begin(), pairs.end(),
        [](pair<int, int> a, pair<int, int> b) { return a.first > b.first; });

    vector<string> ret(nums.size());
    int rank = 1;
    for (const auto& pair : pairs) {
      int index = pair.second;
      if (rank == 1) {
        ret[index] = "Gold Medal";
      } else if (rank == 2) {
        ret[index] = "Silver Medal";
      } else if (rank == 3) {
        ret[index] = "Bronze Medal";
      } else {
        ret[index] = to_string(rank);
      }
      // cout << index << ":" << rank << ":" << ret[index] <<  endl;
      rank++;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums;
  vector<string> act, exp;

  nums = {5, 4, 3, 2, 1};
  act = s.findRelativeRanks(nums);
  exp = {"Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"};
  assert(act == exp);

  nums = {1, 2, 3, 4, 5};
  act = s.findRelativeRanks(nums);
  exp = {"5", "4", "Bronze Medal", "Silver Medal", "Gold Medal"};
  assert(act == exp);

  nums = {4, 5};
  act = s.findRelativeRanks(nums);
  exp = {"Silver Medal", "Gold Medal"};
  assert(act == exp);

  return 0;
}
