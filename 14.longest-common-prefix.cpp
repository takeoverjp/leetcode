/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <string>
#include <vector>
#include <assert.h>

using std::vector;
using std::string;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) {
            return "";
        }
        string ret = strs[0];
        for (const auto& str : strs) {
            size_t size = ret.size();
            for (int i = 0; i < size; i++) {
                if (ret[i] != str[i]) {
                    ret = ret.erase(i);
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

int
main () {
    Solution s;
    vector<string> strs;
    strs = {};
    assert("" == s.longestCommonPrefix(strs));
    strs = {"flower", "flow", "flight"};
    assert("fl" == s.longestCommonPrefix(strs));
    strs = {"dog", "racecar", "car"};
    assert("" == s.longestCommonPrefix(strs));
    strs = {"a", "ab"};
    assert("a" == s.longestCommonPrefix(strs));
    strs = {"ab", "a"};
    assert("a" == s.longestCommonPrefix(strs));
}