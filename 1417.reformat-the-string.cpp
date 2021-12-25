/*
 * @lc app=leetcode id=1417 lang=cpp
 *
 * [1417] Reformat The String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    string reformat(string s) {
        int anum = 0;
        for(auto c:s) if(isalpha(c)) anum++;
        int cnum = s.size() - anum;
        if (abs(cnum-anum) >1) {
            return "";
        }
        char* ret = (char*)alloca(s.size() + 1);
        ret[s.size()] = '\0';
        int aidx = anum <= cnum;
        int cidx = anum > cnum;
        for(auto c: s) {
            if (isalpha(c)) {
                ret[aidx] = c;
                aidx+=2;
            } else {
                ret[cidx] = c;
                cidx+=2;
            }
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  ASSERT_EQ(s.reformat("a0b1c2"), "0a1b2c");
  ASSERT_EQ(s.reformat("a0b1c2d"), "a0b1c2d");
  ASSERT_EQ(s.reformat("a0b1c23"), "0a1b2c3");
  ASSERT_EQ(s.reformat("leetcode"), "");
  ASSERT_EQ(s.reformat("1229857369"), "");
  return 0;
}
