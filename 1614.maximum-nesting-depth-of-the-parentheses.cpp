/*
 * @lc app=leetcode id=1614 lang=cpp
 *
 * [1614] Maximum Nesting Depth of the Parentheses
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxDepth(string s) {
    int depth = 0;
    int ret = depth;
    for (auto c : s) {
      if (c == '(') {
        depth++;
        ret = max(ret, depth);
      } else if (c == ')') {
        depth--;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.maxDepth("(1+(2*3)+((8)/4))+1"), 3);
  ASSERT_EQ(s.maxDepth("(1)+((2))+(((3)))"), 3);
  return 0;
}
