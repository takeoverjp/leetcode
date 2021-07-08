/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int heightChecker(vector<int>& heights) {
    vector<int> sorted(heights);
    std::sort(sorted.begin(), sorted.end());
    int size = heights.size();
    int ret = 0;
    for (int i = 0; i < size; i++) {
      if (heights[i] != sorted[i]) {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> heights;
  heights = {1, 1, 4, 2, 1, 3};
  ASSERT_EQ(s.heightChecker(heights), 3);
  heights = {5, 1, 2, 3, 4};
  ASSERT_EQ(s.heightChecker(heights), 5);
  return 0;
}
