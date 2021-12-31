/*
 * @lc app=leetcode id=1446 lang=cpp
 *
 * [1446] Consecutive Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    int maxPower(string s) {
        char last = '\0';
        int count = 1;
        int ret = count;
        for(auto c : s) {
            if (last == c) {
                count ++;
                ret = max(ret, count);
            } else {
                count = 1;
                last = c;
            }
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  ASSERT_EQ(s.maxPower("leetcode"), 2);
  ASSERT_EQ(s.maxPower("abbcccddddeeeeedcba"), 5);
  return 0;
}
