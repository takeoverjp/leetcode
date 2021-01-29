/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    char first = s[0];
    int len = s.length();
    if (len <= 1) {
      return false;
    }
    for (int i = 1; i < len; i++) {
      if (s[i] == first) {
        int sublen = i;
        if (len % sublen) {
          continue;
        }
 
        for (int j = sublen; j < len; j += sublen) {

          // cout << pattern << " ? " << s.substr(j, sublen) << endl;
          for (int k = 0; k < sublen; k++) {
            if (s[k] != s[j+k]) {
              goto NEXT_SUBLEN;
            }
          }
        }

        return true;

      NEXT_SUBLEN:
        continue;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.repeatedSubstringPattern("a") == false);
  assert(s.repeatedSubstringPattern("aa") == true);
  assert(s.repeatedSubstringPattern("abab") == true);
  assert(s.repeatedSubstringPattern("ababab") == true);
  assert(s.repeatedSubstringPattern("abaabaaba") == true);
  return 0;
}
