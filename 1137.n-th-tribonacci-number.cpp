/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  Solution() {
    map_[0] = 0;
    map_[1] = 1;
    map_[2] = 1;
  }
  int tribonacci(int n) {
    if (map_.count(n)) {
      return map_[n];
    }
    int ret = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    map_[n] = ret;
    return ret;
  }

 private:
  std::unordered_map<int, int> map_;
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.tribonacci(4), 4);
  ASSERT_EQ(s.tribonacci(25), 1389537);
  return 0;
}
