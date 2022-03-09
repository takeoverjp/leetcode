/*
 * @lc app=leetcode id=1832 lang=cpp
 *
 * [1832] Check if the Sentence Is Pangram
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkIfPangram(string sentence) {
    int count[26] = {0};
    for (auto c : sentence) {
      count[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (count[i] == 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.checkIfPangram("thequickbrownfoxjumpsoverthelazydog"), true);
  ASSERT_EQ(s.checkIfPangram("leetcode"), false);
  return 0;
}
