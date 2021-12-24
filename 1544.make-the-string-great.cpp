/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    string makeGood(string s) {
        char* str = (char*)alloca(s.size() + 1);
        int index = 0;
        for ( char c : s) {
            if (index > 0) {
                if (c != str[index-1] && tolower(c) ==tolower( str[index-1])) {
                    index--;
                    continue;
                }
            }
            str[index++] = c;
        }
        str[index] = '\0';
        return string(str);
    }
};
// @lc code=end

int
main () {
  Solution s;
  ASSERT_EQ(s.makeGood("leEeetcode"), "leetcode");
  ASSERT_EQ(s.makeGood("abBAcC"), "");
  ASSERT_EQ(s.makeGood("s"), "s");
  return 0;
}
