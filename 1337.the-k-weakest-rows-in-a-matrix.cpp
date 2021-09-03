/*
 * @lc app=leetcode id=1337 lang=cpp
 *
 * [1337] The K Weakest Rows in a Matrix
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<std::pair<int, int>> sol;
    sol.reserve(mat.size());

    int size = mat.size();
    for (int i = 0; i < size; i++) {
      const auto& row = mat[i];
      sol.emplace_back(std::accumulate(row.begin(), row.end(), 0), i);
    }

    std::sort(sol.begin(), sol.end(), [](const auto& lhs, const auto& rhs) {
      if (lhs.first < rhs.first) {
        return true;
      }
      if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
      }
      return false;
    });

    vector<int> ret(k);
    for (int i = 0; i < k && i < size; i++) {
      ret[i] = sol[i].second;
    }

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> mat;
  vector<int> exp;
  mat = {{1, 1, 0, 0, 0},
         {1, 1, 1, 1, 0},
         {1, 0, 0, 0, 0},
         {1, 1, 0, 0, 0},
         {1, 1, 1, 1, 1}};
  exp = {2, 0, 3};
  ASSERT_EQ(s.kWeakestRows(mat, 3), exp);
  mat = {{1, 0, 0, 0}, {1, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}};
  exp = {0, 2};
  ASSERT_EQ(s.kWeakestRows(mat, 2), exp);
  return 0;
}
