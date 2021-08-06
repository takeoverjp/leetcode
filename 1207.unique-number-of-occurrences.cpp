/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */
#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    std::unordered_map<int, int> count_map;
    for (const auto num : arr) {
      count_map[num]++;
    }
    std::set<int> count_set;
    for (const auto& pair : count_map) {
      count_set.insert(pair.second);
    }
    return count_map.size() == count_set.size();
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {1, 2, 2, 1, 1, 3};
  ASSERT_EQ(s.uniqueOccurrences(arr), true);
  arr = {1, 2};
  ASSERT_EQ(s.uniqueOccurrences(arr), false);
  arr = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
  ASSERT_EQ(s.uniqueOccurrences(arr), true);
  return 0;
}
