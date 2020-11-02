/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <string>
#include <unistd.h>
#include <assert.h>

using std::string;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        size_t len = s.size();
        for (int i = 0; i < len; i++) {
            char c = s[i];
            char n = s[i+1];
            switch(c) {
                case 'I':
                    if (n == 'V' || n == 'X') {
                        sum -= 1;
                    } else {
                        sum += 1;
                    }
                    break;
                case 'V':
                    sum += 5;
                    break;
                case 'X':
                    if (n == 'L' || n == 'C') {
                        sum -= 10;
                    } else {
                        sum += 10;
                    }
                    break;
                case 'L':
                    sum += 50;
                    break;
                case 'C':
                    if (n == 'D' || n == 'M') {
                        sum -= 100;
                    } else {
                        sum += 100;
                    }
                    break;
                case 'D':
                    sum += 500;
                    break;
                case 'M':
                    sum += 1000;
                    break;
            }
        }
        return sum;
    }
};
// @lc code=end


int
main (void) {
    Solution s;
    assert(3 == s.romanToInt("III"));
    assert(4 == s.romanToInt("IV"));
    assert(9 == s.romanToInt("IX"));
    assert(58 == s.romanToInt("LVIII"));
    assert(1994 == s.romanToInt("MCMXCIV"));
    return 0;
}