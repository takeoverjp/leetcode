/*
 * @lc app=leetcode id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int longestPalindrome(string s) {
    constexpr int size = 'z' - 'A' + 1;
    int count[size] = {0};
    int len = s.length();
    int ret = 0;
    for (int i = 0; i < len; i++) {
      int index = s[i] - 'A';
      if (count[index] == 0) {
        count[index] = 1;
      } else {
        count[index] = 0;
        ret += 2;
      }
    }
    for (int i = 0; i < size; i++) {
      if (count[i] > 0) {
        ret++;
        break;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.longestPalindrome("abccccdd") == 7);
  assert(s.longestPalindrome("a") == 1);
  assert(s.longestPalindrome("bb") == 2);
  assert(s.longestPalindrome("AZccccdd") == 7);
  assert(s.longestPalindrome("") == 0);
  assert(s.longestPalindrome("zeusnilemacaronimaisanitratetartinasiaminoracamelinsuez") == 55);
  return 0;
}
