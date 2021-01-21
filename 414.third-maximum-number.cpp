/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

#include <bits/stdc++.h>
#include <stdint.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int64_t max[3] = {INT64_MIN, INT64_MIN, INT64_MIN};

        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int curr = nums[i];
            for (int j = 0; j < 3; j++) {
                if (curr == max[j]) {
                    break;
                }
                if (curr > max[j]) {
                    for (int k = 2; k > j; k--) {
                        max[k] = max[k-1];
                    }
                    max[j] = curr;
                    break;
                }
            }
        }

        if (max[2] == INT64_MIN) {
            return max[0];
        }

        return max[2];
    }
};
// @lc code=end

int main()
{
    Solution s;
    vector<int> nums;

    {
        int array[] = {3, 2, 1};
        nums = vector<int>(array, array + sizeof(array) / sizeof(array[0]));
        assert(s.thirdMax(nums) == 1);
    }
    {
        int array[] = {1, 2};
        nums = vector<int>(array, array + sizeof(array) / sizeof(array[0]));
        assert(s.thirdMax(nums) == 2);
    }
    {
        int array[] = {2, 2, 3, 1};
        nums = vector<int>(array, array + sizeof(array) / sizeof(array[0]));
        assert(s.thirdMax(nums) == 1);
    }
    return 0;
}
