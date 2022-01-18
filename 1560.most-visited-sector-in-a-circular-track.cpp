/*
 * @lc app=leetcode id=1560 lang=cpp
 *
 * [1560] Most Visited Sector in  a Circular Track
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> mostVisited(int n, vector<int>& rounds) {
    int start = rounds[0];
    int end = rounds[rounds.size() - 1];
    if (start <= end) {
      vector<int> ret(end - start + 1);
      for (int i = 0; i < ret.size(); i++) {
        ret[i] = start + i;
      }
      return ret;
    }
    vector<int> ret(end + n - start + 1);
    for (int i = 0; i < end; i++) {
      ret[i] = i + 1;
    }
    for (int i = end; i < ret.size(); i++) {
      ret[i] = i + start - end;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> rounds, exp;
  rounds = {1, 3, 1, 2};
  exp = {1, 2};
  ASSERT_EQ(s.mostVisited(4, rounds), exp);
  rounds = {2, 1, 2, 1, 2, 1, 2, 1, 2};
  exp = {2};
  ASSERT_EQ(s.mostVisited(2, rounds), exp);
  rounds = {1, 3, 5, 7};
  exp = {1, 2, 3, 4, 5, 6, 7};
  ASSERT_EQ(s.mostVisited(7, rounds), exp);
  rounds = {4, 1, 3, 5, 2};
  exp = {1, 2, 4, 5, 6, 7};
  ASSERT_EQ(s.mostVisited(7, rounds), exp);
  return 0;
}
