/*
 * @lc app=leetcode id=1309 lang=cpp
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string freqAlphabets(string s) {
    int size = s.length();
    std::string ret;
    ret.reserve(size);
    for (int i = size - 1; i >= 0; i--) {
      char c = 'a' - 1;
      if (s[i] == '#') {
        c += (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
        i -= 2;
      } else {
        c += s[i] - '0';
      }
      ret = c + ret;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.freqAlphabets("10#11#12"), "jkab");
  ASSERT_EQ(s.freqAlphabets("1326#"), "acz");
  ASSERT_EQ(s.freqAlphabets("25#"), "y");
  ASSERT_EQ(s.freqAlphabets(
                "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#"),
            "abcdefghijklmnopqrstuvwxyz");
  return 0;
}
