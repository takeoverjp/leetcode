/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  char findTheDifference(string s, string t) {
    int count[26] = {0};
    int slen = s.length();
    for (int i = 0; i < slen; i++) {
      count[s[i] - 'a']--;
      count[t[i] - 'a']++;
    }

    count[t[slen] - 'a']++;

    for (int i = 0; i < 26; i++) {
      if (count[i]) {
        return 'a' + i;
      }
    }

    return '\0';
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.findTheDifference("abcd", "abcde") == 'e');
  assert(s.findTheDifference("", "y") == 'y');
  assert(s.findTheDifference("a", "aa") == 'a');
  assert(s.findTheDifference("ae", "aea") == 'a');
  assert(s.findTheDifference("ae", "eaa") == 'a');
  return 0;
}
