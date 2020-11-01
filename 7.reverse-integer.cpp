/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <vector>
#include <cstdint>

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long y = 0;
        while (x) {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return (y >= INT32_MAX || y <= INT32_MIN) ? 0 : y;
    }
};
// @lc code=end

