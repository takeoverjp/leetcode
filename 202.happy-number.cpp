/*
 * @lc app=leetcode id=202 lang=cpp
 *
 * [202] Happy Number
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int fast = next(n), slow = n;
        while(fast != slow) {
            fast = next(next(fast));
            slow = next(slow);
        }
        return 1 == fast;
    }
    private:
    int next(int n) {
        int ret = 0;
        while (n) {
            ret += pow(n % 10, 2);
            n /= 10;
        }
        return ret;
    }
};
// @lc code=end

int
main () {
  Solution s;
  assert(s.isHappy(0) == false);
  assert(s.isHappy(1) == true);
  assert(s.isHappy(2) == false);
  assert(s.isHappy(13) == true);
  assert(s.isHappy(19) == true);
  return 0;
}
