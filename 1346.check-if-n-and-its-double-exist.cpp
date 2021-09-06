/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool checkIfExist(vector<int>& arr) {
    std::sort(std::begin(arr), std::end(arr));
    int size = arr.size();
    for (int i = 0; i < size - 1; i++) {
      int num = arr[i];
      if (num < 0) {
        for (int j = i - 1; j >= 0; j--) {
          if (arr[j] == 2 * num) {
            return true;
          } else if (arr[j] < 2 * num) {
            break;
          }
        }
      } else {
        for (int j = i + 1; j < size; j++) {
          if (arr[j] == 2 * num) {
            return true;
          } else if (arr[j] > 2 * num) {
            break;
          }
        }
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> arr;
  arr = {10, 2, 5, 3};
  ASSERT_EQ(s.checkIfExist(arr), true);
  arr = {7, 1, 14, 11};
  ASSERT_EQ(s.checkIfExist(arr), true);
  arr = {3, 1, 7, 11};
  ASSERT_EQ(s.checkIfExist(arr), false);
  arr = {-10, 12, -20, -8, 15};
  ASSERT_EQ(s.checkIfExist(arr), true);
  return 0;
}
