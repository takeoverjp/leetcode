/*
 * @lc app=leetcode id=575 lang=cpp
 *
 * [575] Distribute Candies
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;


// @lc code=start
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        set<int> uniq(candyType.begin(), candyType.end());
        return min(uniq.size(), candyType.size()/2);
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> types;
  types = {1,1,2,2,3,3};
  ASSERT_EQ(s.distributeCandies(types), 3);
  types = {1,1,2,3};
  ASSERT_EQ(s.distributeCandies(types), 2);
  types = {1,1,1,1};
  ASSERT_EQ(s.distributeCandies(types), 1);
  return 0;
}

