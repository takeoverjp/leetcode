/*
 * @lc app=leetcode id=1128 lang=cpp
 *
 * [1128] Number of Equivalent Domino Pairs
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    struct VectorHasher {
      int operator()(const vector<int>& V) const {
        uint32_t hash = V.size();
        for (uint32_t i : V) {
          hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        return hash;
      }
    };
    for (auto& domino : dominoes) {
      std::sort(domino.begin(), domino.end(),
                [](auto& lhs, auto& rhs) { return lhs < rhs; });
    }
    std::unordered_map<vector<int>, int, VectorHasher> counts;
    for (const auto& domino : dominoes) {
      counts[domino] += 1;
    }
    int ret = 0;
    for (const auto& count : counts) {
      if (count.second <= 1) {
        continue;
      }
      ret += count.second * (count.second - 1) / 2;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> dominoes;
  dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
  ASSERT_EQ(s.numEquivDominoPairs(dominoes), 1);
  dominoes = {{1, 2}, {2, 1}, {1, 2}, {5, 6}};
  ASSERT_EQ(s.numEquivDominoPairs(dominoes), 3);
  return 0;
}
