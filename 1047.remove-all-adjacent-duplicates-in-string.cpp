/*
 * @lc app=leetcode id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string removeDuplicates(string s) {
    size_t size = s.length() + 1;
    char* ret = static_cast<char*>(alloca(size));
    memset(ret, 0, size);
    int index = 0;
    for (auto c : s) {
      while (index > 0 && ret[index - 1] == c) {
        ret[--index] = '\0';
        goto NEXT_CHAR;
      }
      ret[index++] = c;
    NEXT_CHAR:;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.removeDuplicates("abbaca"), "ca");
  ASSERT_EQ(s.removeDuplicates("azxxzy"), "ay");
  ASSERT_EQ(s.removeDuplicates("aaaaaaaa"), "");
  return 0;
}
