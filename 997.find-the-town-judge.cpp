/*
 * @lc app=leetcode id=997 lang=cpp
 *
 * [997] Find the Town Judge
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int findJudge(int n, vector<vector<int>>& trust) {
    bool* is_trust_anyone = static_cast<bool*>(alloca(sizeof(bool) * n));
    memset(is_trust_anyone, 0, sizeof(bool) * n);
    for (const auto& t : trust) {
      is_trust_anyone[t[0] - 1] = true;
    }
    short* counts = static_cast<short*>(alloca(sizeof(short) * n));
    memset(counts, 0, sizeof(short) * n);
    for (const auto& t : trust) {
      counts[t[1] - 1]++;
    }
    for (int i = 0; i < n; i++) {
      if (!is_trust_anyone[i] && counts[i] == n - 1) {
        return i + 1;
      }
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> trust;
  trust = {{1, 2}};
  ASSERT_EQ(s.findJudge(2, trust), 2);
  trust = {{1, 3}, {2, 3}};
  ASSERT_EQ(s.findJudge(3, trust), 3);
  trust = {{1, 3}, {2, 3}, {3, 1}};
  ASSERT_EQ(s.findJudge(3, trust), -1);
  trust = {{1, 2}, {2, 3}};
  ASSERT_EQ(s.findJudge(3, trust), -1);
  trust = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
  ASSERT_EQ(s.findJudge(4, trust), 3);
  return 0;
}
