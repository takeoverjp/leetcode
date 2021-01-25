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
        for (int i = 0; i < len; i++)
        {
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -1 * nums[index];
            }
        }
        vector<int> ret;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
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
