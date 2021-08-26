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
    findMax(arr, 0);
    return arr;
  }

 private:
  int findMax(vector<int>& arr, int start) {
    int orig = arr[start];
    int size = arr.size();
    if (start == size - 1) {
      arr[start] = -1;
      return orig;
    }
    arr[start] = findMax(arr, start + 1);
    return std::max(orig, arr[start]);
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
