/*
 * @lc app=leetcode id=1805 lang=cpp
 *
 * [1805] Number of Different Integers in a String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numDifferentIntegers(string word) {
    set<string> integers;
    bool in_integer = false;
    int pos = 0;
    int len = word.length();
    for (int i = 0; i <= len; i++) {
      if (in_integer) {
        if (!isdigit(word[i])) {
          while (word[pos] == '0') {
            pos++;
          }
          integers.insert(word.substr(pos, i - pos));
          in_integer = false;
        }
      } else if (isdigit(word[i])) {
        pos = i;
        in_integer = true;
      }
    }
    return integers.size();
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.numDifferentIntegers("a123bc34d8ef34"), 3);
  ASSERT_EQ(s.numDifferentIntegers("leet1234code234"), 2);
  ASSERT_EQ(s.numDifferentIntegers("a1b01c001"), 1);
  ASSERT_EQ(s.numDifferentIntegers("0a0"), 1);
  return 0;
}
