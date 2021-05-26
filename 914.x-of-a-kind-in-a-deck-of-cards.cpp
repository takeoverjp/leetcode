/*
 * @lc app=leetcode id=914 lang=cpp
 *
 * [914] X of a Kind in a Deck of Cards
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    map<int, int> counts;
    for (auto num : deck) {
      if (counts.count(num) == 0) {
        counts[num] = 1;
      } else {
        counts[num]++;
      }
    }
    int min_num = INT_MAX;
    for (const auto& pair : counts) {
      min_num = min(min_num, pair.second);
    }
    for (int i = 2; i <= min_num; i++) {
      bool is_ok = true;
      for (const auto& pair : counts) {
        if (pair.second % i) {
          is_ok = false;
          break;
        }
      }
      if (is_ok) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> deck;
  deck = {1, 2, 3, 4, 4, 3, 2, 1};
  ASSERT_EQ(s.hasGroupsSizeX(deck), true);
  deck = {1, 1, 1, 2, 2, 2, 3, 3};
  ASSERT_EQ(s.hasGroupsSizeX(deck), false);
  deck = {1};
  ASSERT_EQ(s.hasGroupsSizeX(deck), false);
  deck = {1, 1};
  ASSERT_EQ(s.hasGroupsSizeX(deck), true);
  deck = {1, 1, 2, 2, 2, 2};
  ASSERT_EQ(s.hasGroupsSizeX(deck), true);
  deck = {0, 0, 0, 1, 1, 1, 2, 2, 2};
  ASSERT_EQ(s.hasGroupsSizeX(deck), true);
  return 0;
}
