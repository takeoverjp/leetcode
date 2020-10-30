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
        long long y = 0;
        while (x) {
            y *= 10;
            y += x % 10;
            x /= 10;
        }
        if (y >= INT32_MAX || y <= INT32_MIN) {
            return 0;
        }
        return y;
    }
};
// @lc code=end

