/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int last = 0;
    bool is_first = true;

    for (auto it = nums.begin(); it != nums.end();) {
      if (is_first) {
        is_first = false;
        last = *it;
        ++it;
        continue;
      }

      if (last == *it) {
        it = nums.erase(it);
        continue;
      }

      last = *it;
      ++it;
    }

    return nums.size();
  }
};
// @lc code=end
