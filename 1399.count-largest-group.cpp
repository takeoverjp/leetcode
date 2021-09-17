/*
 * @lc app=leetcode id=1399 lang=cpp
 *
 * [1399] Count Largest Group
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countLargestGroup(int n) {
    std::unordered_map<int, int> counts;
    for (int i = 1; i <= n; i++) {
      int work = i;
      int sum = 0;
      while (work) {
        sum += work % 10;
        work /= 10;
      }
      counts[sum]++;
    }
    std::vector<int> vector_count;
    for (auto count : counts) {
      vector_count.push_back(count.second);
    }
    int max = *std::max_element(vector_count.begin(), vector_count.end());
    int ret = 0;
    for (int count : vector_count) {
      if (count == max) {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.countLargestGroup(1), 1);
  ASSERT_EQ(s.countLargestGroup(2), 2);
  ASSERT_EQ(s.countLargestGroup(9), 9);
  ASSERT_EQ(s.countLargestGroup(10), 1);
  ASSERT_EQ(s.countLargestGroup(11), 2);
  ASSERT_EQ(s.countLargestGroup(12), 3);
  ASSERT_EQ(s.countLargestGroup(13), 4);
  ASSERT_EQ(s.countLargestGroup(18), 9);
  ASSERT_EQ(s.countLargestGroup(19), 9);
  ASSERT_EQ(s.countLargestGroup(20), 1);
  ASSERT_EQ(s.countLargestGroup(21), 2);
  ASSERT_EQ(s.countLargestGroup(22), 3);
  ASSERT_EQ(s.countLargestGroup(27), 8);
  ASSERT_EQ(s.countLargestGroup(28), 8);
  ASSERT_EQ(s.countLargestGroup(29), 8);
  ASSERT_EQ(s.countLargestGroup(30), 1);
  return 0;
}
