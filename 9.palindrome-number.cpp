/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if ((x < 0) || (x % 10 == 0)) return false;
        int rev = 0;
        while (x > rev) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return (x == rev) || (x == rev/10);
    }
};
// @lc code=end

int
main () {
  Solution s;
  ASSERT_EQ(s.isPalindrome(121), true);
  ASSERT_EQ(s.isPalindrome(-121), false);
  ASSERT_EQ(s.isPalindrome(10), false);
  ASSERT_EQ(s.isPalindrome(-101), false);
  return 0;
}
