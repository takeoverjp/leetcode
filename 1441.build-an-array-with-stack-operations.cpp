/*
 * @lc app=leetcode id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ret;
        int curr = 1;
        for (int i = 0; i < target.size(); i++) {
            while(target[i] > curr) {
                ret.push_back("Push");
                ret.push_back("Pop");
                curr++;
            }
            ret.push_back("Push");
            curr++;
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> target;
  vector<string> exp;
  target = {1, 3};
  exp = {"Push", "Push", "Pop", "Push"};
  ASSERT_EQ(s.buildArray(target, 3), exp);
  target = {1, 2, 3};
  exp = {"Push", "Push", "Push"};
  ASSERT_EQ(s.buildArray(target, 3), exp);
  target = {1, 2, 3};
  exp = {"Push", "Push", "Push"};
  ASSERT_EQ(s.buildArray(target, 4), exp);
  return 0;
}
