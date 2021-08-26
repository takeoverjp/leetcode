/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int max_num = *arr.rbegin();
    *arr.rbegin() = -1;
    for (auto it = arr.rbegin() + 1; it != arr.rend(); it++) {
      int orig_num = *it;
      *it = max_num;
      max_num = std::max(max_num, orig_num);
    }
    return arr;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr, exp;

  arr = {17, 18, 5, 4, 6, 1};
  exp = {18, 6, 6, 6, 1, -1};
  ASSERT_EQ(s.replaceElements(arr), exp);

  arr = {400};
  exp = {-1};
  ASSERT_EQ(s.replaceElements(arr), exp);

  return 0;
}
