/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include <assert.h>
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return len;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> vec;
  vec = {1, 3, 5, 6};
  assert(2 == s.searchInsert(vec, 5));
  assert(1 == s.searchInsert(vec, 2));
  assert(4 == s.searchInsert(vec, 7));
  assert(0 == s.searchInsert(vec, 0));
  vec = {1};
  assert(0 == s.searchInsert(vec, 0));
  vec = {};
  assert(0 == s.searchInsert(vec, 1));
  vec = {-15, 0, 13};
  assert(1 == s.searchInsert(vec, -13));
}