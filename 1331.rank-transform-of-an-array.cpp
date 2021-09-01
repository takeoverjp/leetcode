/*
 * @lc app=leetcode id=1331 lang=cpp
 *
 * [1331] Rank Transform of an Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sorted{arr};
    std::sort(sorted.begin(), sorted.end());
    std::unordered_map<int, int> rank;
    for (const auto& val : sorted) {
      rank.emplace(val, rank.size() + 1);
    }
    int size = sorted.size();
    for (int i = 0; i < size; i++) {
      sorted[i] = rank[arr[i]];
    }
    return sorted;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr, exp;
  arr = {40, 10, 20, 30};
  exp = {4, 1, 2, 3};
  ASSERT_EQ(s.arrayRankTransform(arr), exp);
  arr = {100, 100, 100};
  exp = {1, 1, 1};
  ASSERT_EQ(s.arrayRankTransform(arr), exp);
  arr = {37, 12, 28, 9, 100, 56, 80, 5, 12};
  exp = {5, 3, 4, 2, 8, 6, 7, 1, 3};
  ASSERT_EQ(s.arrayRankTransform(arr), exp);
  return 0;
}
