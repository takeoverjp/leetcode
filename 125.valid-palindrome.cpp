/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s) {
    string lower = "";
    for (char c : s) {
      if (isalnum(c)) {
        if (c >= 'a') {
            c -= 'a' - 'A';
        }
        lower += c;
      }
    }
    int len = lower.length();
    int mid = len / 2;
    for (int i = 0; i < mid; i++) {
      if (lower[i] != lower[len - i - 1]) return false;
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.isPalindrome(""));
  assert(s.isPalindrome("A man, a plan, a canal: Panama"));
  assert(!s.isPalindrome("race a car"));
  assert(s.isPalindrome("a"));
  assert(s.isPalindrome("1"));
  assert(!s.isPalindrome("ab"));
  assert(s.isPalindrome("1:a1"));
  return 0;
}
