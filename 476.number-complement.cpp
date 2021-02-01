/*
 * @lc app=leetcode id=476 lang=cpp
 *
 * [476] Number Complement
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int findComplement(int num) {
    uint sum = 1;
    while (sum <= (uint)num) {
      sum <<= 1;
    }
    return sum - num - 1;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.findComplement(15) == 0);
  assert(s.findComplement(8) == 7);
  assert(s.findComplement(5) == 2);
  assert(s.findComplement(1) == 0);
  return 0;
}
