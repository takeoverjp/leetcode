/*
 * @lc app=leetcode id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 private:
  string summarize(int start, int end) {
    if (start == end) {
      return to_string(start);
    } else {
      return to_string(start) + "->" + to_string(end);
    }
  }

 public:
  vector<string> summaryRanges(vector<int>& nums) {
    int start = INT_MIN, end = INT_MIN;
    vector<string> ret;
    size_t size = nums.size();
    for (int i = 0; i < size; i++) {
      if (i == size - 1) {
        if (i == 0) {
          ret.push_back(summarize(nums[i], nums[i]));
        } else if (nums[i] == end + 1) {
          end = nums[i];
          ret.push_back(summarize(start, end));
        } else {
          ret.push_back(summarize(start, end));
          ret.push_back(to_string(nums[i]));
        }
        return ret;
      }

      if (i == 0) {
        start = nums[i];
        end = start;
        continue;
      }

      if (nums[i] == end + 1) {
        end = nums[i];
        continue;
      }

      ret.push_back(summarize(start, end));
      start = nums[i];
      end = start;
    }
    return ret;
  }
};
// @lc code=end
