/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count =0;
        for (auto num : arr) {
            if (num % 2) {
                count++;
                if (count >= 3) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> arr;
  arr = {2,6,4,1};
  ASSERT_EQ(s.threeConsecutiveOdds(arr), false);
  arr = {1,2,34,3,4,5,7,23,12};
  ASSERT_EQ(s.threeConsecutiveOdds(arr), true);
  return 0;
}
