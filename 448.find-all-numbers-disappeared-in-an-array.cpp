/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int len = nums.size();
        if (len == 0) {
            return {};
        }
        bool is_appeared[len];
        for (int i = 0; i < len; i++)
        {
            is_appeared[i] = false;
        }
        for (const auto num : nums)
        {
            is_appeared[num - 1] = true;
        }
        vector<int> ret;
        for (int i = 0; i < len; i++)
        {
            if (!is_appeared[i])
            {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    Solution s;
    {
        vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
        vector<int> exp{5, 6};
        assert(s.findDisappearedNumbers(nums) == exp);
    }
    {
        vector<int> nums{};
        vector<int> exp{};
        assert(s.findDisappearedNumbers(nums) == exp);
    }
    return 0;
}
