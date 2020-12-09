/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int ret = 0;
        while (n) {
            n /= 5;
            ret += n;
        }
        return ret;
    }
};
// @lc code=end

