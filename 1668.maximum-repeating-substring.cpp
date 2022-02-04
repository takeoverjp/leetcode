/*
 * @lc app=leetcode id=1668 lang=cpp
 *
 * [1668] Maximum Repeating Substring
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxRepeating(string sequence, string word) {
    int ret = 0;
    int len = sequence.length();
    int wlen = word.length();
    for (int i = 0; i < len; i++) {
      for (int j = 0; i + j < len; j++) {
        if (sequence[i + j] != word[j % wlen]) {
          break;
        }
        ret = max(ret, (j + 1) / wlen);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.maxRepeating("ababc", "ab"), 2);
  ASSERT_EQ(s.maxRepeating("ababc", "ba"), 1);
  ASSERT_EQ(s.maxRepeating("ababc", "ac"), 0);
  return 0;
}
