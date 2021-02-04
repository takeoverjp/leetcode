/*
 * @lc app=leetcode id=492 lang=cpp
 *
 * [492] Construct the Rectangle
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ret;
        int max = sqrt(area);
        for (int candidate = max; candidate >= 1; candidate--) {
            if (area % candidate == 0) {
                ret.push_back(area / candidate);
                ret.push_back(candidate);
                break;
            }
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> ret;
  ret = s.constructRectangle(4);
  assert(ret[0] == 2);
  assert(ret[1] == 2);

  ret = s.constructRectangle(37);
  assert(ret[0] == 37);
  assert(ret[1] == 1);

  ret = s.constructRectangle(122122);
  assert(ret[0] == 427);
  assert(ret[1] == 286);
  return 0;
}
