/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int firstUniqChar(string s) {
    int len = s.length();
    int pos[26];
    for (int i = 0; i < sizeof(pos) / sizeof(pos[0]); i++) {
      pos[i] = -1;
    }

    for (int i = 0; i < len; i++) {
      int index = s[i] - 'a';
      if (pos[index] >= 0) {
        pos[index] = INT_MAX;
      } else {
        pos[index] = i;
      }
    }

    int ret = INT_MAX;
    for (int i = 0; i < sizeof(pos) / sizeof(pos[0]); i++) {
      if (pos[i] < 0) {
        continue;
      }
      if (pos[i] < ret) {
        ret = pos[i];
      }
    }

    if (ret == INT_MAX) {
        return -1;
    }

    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.firstUniqChar("") == -1);
  assert(s.firstUniqChar("ll") == -1);
  assert(s.firstUniqChar("leetcode") == 0);
  assert(s.firstUniqChar("loveleetcode") == 2);
  return 0;
}
