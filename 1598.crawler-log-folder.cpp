/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int ret = 0;
    for (const auto& log : logs) {
      if (log == "../") {
        ret = max(0, ret - 1);
      } else if (log == "./") {
        continue;
      } else {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> logs;
  logs = {"d1/", "d2/", "../", "d21/", "./"};
  ASSERT_EQ(s.minOperations(logs), 2);
  logs = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
  ASSERT_EQ(s.minOperations(logs), 3);
  logs = {"d1/", "../", "../", "../"};
  ASSERT_EQ(s.minOperations(logs), 0);
  return 0;
}
