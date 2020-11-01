/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <cstdint>

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

