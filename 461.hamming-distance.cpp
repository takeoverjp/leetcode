/*
 * @lc app=leetcode id=461 lang=cpp
 *
 * [461] Hamming Distance
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
      if ((x^y)&(1<<i)) {
        ret++;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.hammingDistance(1, 4) == 2);
  assert(s.hammingDistance(0, 0) == 0);
  assert(s.hammingDistance(4, 1) == 2);
  assert(s.hammingDistance(4, 4) == 0);
  assert(s.hammingDistance(93, 73) == 2);
  assert(s.hammingDistance(1, 0x40000000) == 2);
  return 0;
}
