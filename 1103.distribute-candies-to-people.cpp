/*
 * @lc app=leetcode id=1103 lang=cpp
 *
 * [1103] Distribute Candies to People
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> distributeCandies(int candies, int num_people) {
    vector<int> ret(num_people, 0);
    int count = 1;
    while (candies > 0) {
      for (int i = 0; i < num_people; i++) {
        int increment = std::min(count, candies);
        ret[i] += increment;
        candies -= increment;
        count++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> exp;
  exp = {1, 2, 3, 1};
  ASSERT_EQ(s.distributeCandies(7, 4), exp);
  exp = {5, 2, 3};
  ASSERT_EQ(s.distributeCandies(10, 3), exp);
  return 0;
}
