/*
 * @lc app=leetcode id=1854 lang=cpp
 *
 * [1854] Maximum Population Year
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maximumPopulation(vector<vector<int>>& logs) {
    int ret = logs[0][0];
    int max_count = 0;
    int count[101] = {0};
    for (auto& log : logs) {
      for (int i = log[0]; i < log[1]; i++) {
        count[i - 1950]++;
        if (count[i - 1950] > max_count) {
          max_count = count[i - 1950];
        }
      }
    }
    for (int i = 0; i <= sizeof(count) / sizeof(count[0]); i++) {
      if (count[i] == max_count) {
        ret = i + 1950;
        break;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<vector<int>> logs;
  logs = {{1993, 1999}, {2000, 2010}};
  ASSERT_EQ(s.maximumPopulation(logs), 1993);
  logs = {{1950, 1961}, {1960, 1971}, {1970, 1981}};
  ASSERT_EQ(s.maximumPopulation(logs), 1960);
  return 0;
}
