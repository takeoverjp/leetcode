/*
 * @lc app=leetcode id=717 lang=cpp
 *
 * [717] 1-bit and 2-bit Characters
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool isOneBitCharacter(vector<int>& bits) {
    int size = bits.size();
    for (int i = 0; i < size; i++) {
      if (i == size - 1) {
        return bits[i] == 0;
      }
      if (bits[i]) {
        i++;
      }
    }
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> bits;
  bits = {0};
  ASSERT_EQ(s.isOneBitCharacter(bits), true);
  bits = {1, 0, 0};
  ASSERT_EQ(s.isOneBitCharacter(bits), true);
  bits = {1, 1, 1, 0};
  ASSERT_EQ(s.isOneBitCharacter(bits), false);
  return 0;
}
