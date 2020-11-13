/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

#include <cassert>
#include <cstring>
#include <string>

using namespace std;

// @lc code=start
class Solution {
 public:
  int strStr(string haystack, string needle) {
    size_t hlen = haystack.length();
    size_t nlen = needle.length();

    if (nlen == 0) {
      return 0;
    }

    if (hlen < nlen) {
      return -1;
    }

    for (u_int i = 0; i + nlen <= hlen; i++) {
      for (u_int j = 0; j < nlen; j++) {
        for (u_int k = 0; j + k < nlen; k++) {
          if (haystack[i + k] != needle[j + k]) {
            goto NEXT_LOOP;
          }
        }
        return i;
      }
    NEXT_LOOP:;
    }
    return -1;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.strStr("a", "a") == 0);
  assert(s.strStr("aaaaa", "bba") == -1);
  assert(s.strStr("hello", "ll") == 2);
  assert(s.strStr("", "bba") == -1);
  assert(s.strStr("aaaaa", "") == 0);
  assert(s.strStr("aaaaa", "a") == 0);
  assert(s.strStr("aaaaa", "aaaaaa") == -1);
  printf("OK\n");
}