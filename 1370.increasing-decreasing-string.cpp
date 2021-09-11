/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string sortString(string s) {
    string ret;
    ret.reserve(s.size());
    int counts[26] = {0};
    for (const auto c : s) {
      counts[c - 'a']++;
    }
    bool any_progress = false;
    do {
      any_progress = false;
      for (int i = 0; i < 26; i++) {
        if (counts[i]) {
          ret += 'a' + i;
          counts[i]--;
          any_progress = true;
        }
      }
      for (int i = 25; i >= 0; i--) {
        if (counts[i]) {
          ret += 'a' + i;
          counts[i]--;
          any_progress = true;
        }
      }
    } while (any_progress);
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.sortString("aaaabbbbcccc"), "abccbaabccba");
  ASSERT_EQ(s.sortString("rat"), "art");
  ASSERT_EQ(s.sortString("leetcode"), "cdelotee");
  ASSERT_EQ(s.sortString("gggggggg"), "gggggggg");
  ASSERT_EQ(s.sortString("spo"), "ops");
  return 0;
}
