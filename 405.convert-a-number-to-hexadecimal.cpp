/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";

        char hex[9] = {0};
        int32_t nums32 = num;
        uint32_t numu32 = (uint32_t)nums32;

        int i = 0;
        while(numu32) {
            char h = numu32 % 16;
            hex[7 - i++] = (h < 10) ? (h + '0') : (h - 10 + 'a');
            numu32 /= 16;
        }

        return std::string(hex + (8-i));
    }
};
// @lc code=end

int
main () {
  Solution s;
  assert(s.toHex(0) == "0");
  assert(s.toHex(26) == "1a");
  assert(s.toHex(-1) == "ffffffff");
  return 0;
}
