/*
 * @lc app=leetcode id=1189 lang=cpp
 *
 * [1189] Maximum Number of Balloons
 */
#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxNumberOfBalloons(string text) {
    int char_num[26];
    memset(char_num, 0, sizeof(char_num));
    for (const auto c : text) {
      char_num[c - 'a']++;
    }

    char_num['l' - 'a'] /= 2;
    char_num['o' - 'a'] /= 2;

    int ret = INT_MAX;
    ret = std::min(ret, char_num['b' - 'a']);
    ret = std::min(ret, char_num['a' - 'a']);
    ret = std::min(ret, char_num['l' - 'a']);
    ret = std::min(ret, char_num['o' - 'a']);
    ret = std::min(ret, char_num['n' - 'a']);
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.maxNumberOfBalloons("nlaebolko"), 1);
  ASSERT_EQ(s.maxNumberOfBalloons("loonbalxballpoon"), 2);
  ASSERT_EQ(s.maxNumberOfBalloons("leetcood"), 0);
  return 0;
}
