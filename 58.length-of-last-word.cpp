/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        s = s.substr(0, s.find_last_not_of(' ') + 1);
        return s.length() - s.find_last_of(' ') - 1;
    }
};
// @lc code=end

int
main () {
  Solution s;
  assert(s.lengthOfLastWord("a ") == 1);
  assert(s.lengthOfLastWord("Hello ") == 5);
  assert(s.lengthOfLastWord("Hello World") == 5);
  assert(s.lengthOfLastWord(" ") == 0);
  return 0;
}
