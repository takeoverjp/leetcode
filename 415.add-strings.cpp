/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int len1 = num1.length();
        int len2 = num2.length();
        int max_len = max(len1, len2);

        int carry = 0;
        string ret = "";
        for (int i = 0; (i < max_len) || (carry > 0); i++)
        {
            int dig1 = 0;
            int dig2 = 0;

            if (i < len1)
            {
                dig1 = num1[len1 - i - 1] - '0';
            }
            if (i < len2)
            {
                dig2 = num2[len2 - i - 1] - '0';
            }

            int sum = dig1 + dig2 + carry;
            carry = sum / 10;
            ret = (char)((sum % 10) + '0') + ret;
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    Solution s;
    assert(s.addStrings("1", "2") == "3");
    assert(s.addStrings("11", "9") == "20");
    assert(s.addStrings("999", "1") == "1000");
    return 0;
}
