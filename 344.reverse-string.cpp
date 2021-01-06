/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        if (len == 0) {
            return;
        }
        for (int i = 0; i <= (len - 1) / 2; i++) {
            char tmp = s[i];
            s[i] = s[len-i-1];
            s[len-i-1] = tmp;
        }
    }
};
// @lc code=end

// ["a","m","a","n","a","P"," ",":","l","a","n","a","c"," "," ","a",",","n","a","l","p"," ","a"," ",",","n","a","m"," ","A"]
// ["a","m","a","n","a","P"," ",":","l","a","n","a","c"," ","a"," ",",","n","a","l","p"," ","a"," ",",","n","a","m"," ","A"]
