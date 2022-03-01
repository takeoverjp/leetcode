/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findCenter(vector<vector<int>>& edges) {
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) {
      return edges[0][0];
    }
    return edges[0][1];
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> edges;
  edges = {{1, 2}, {2, 3}, {4, 2}};
  ASSERT_EQ(s.findCenter(edges), 2);
  edges = {{1, 2}, {5, 1}, {1, 3}, {1, 4}};
  ASSERT_EQ(s.findCenter(edges), 1);

  return 0;
}
