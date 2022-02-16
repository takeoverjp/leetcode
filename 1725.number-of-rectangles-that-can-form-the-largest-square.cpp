/*
 * @lc app=leetcode id=1725 lang=cpp
 *
 * [1725] Number Of Rectangles That Can Form The Largest Square
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countGoodRectangles(vector<vector<int>>& rectangles) {
    unordered_map<int, int> counts;
    int largest = 0;
    for (const auto& rect : rectangles) {
      int sq = min(rect[0], rect[1]);
      counts[sq]++;
      largest = max(largest, sq);
    }
    return counts[largest];
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.countGoodRectangles(), );
  return 0;
}
