/*
 * @lc app=leetcode id=1720 lang=cpp
 *
 * [1720] Decode XORed Array
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> decode(vector<int>& encoded, int first) {
    size_t size = encoded.size();
    vector<int> ret(size + 1);
    ret[0] = first;
    for (size_t i = 0; i < size; i++) {
      ret[i + 1] = ret[i] ^ encoded[i];
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> encoded, expected;
  encoded = {1, 2, 3};
  expected = {1, 0, 2, 1};
  ASSERT_EQ(s.decode(encoded, 1), expected);
  encoded = {6, 2, 7, 3};
  expected = {4, 2, 0, 7, 4};
  ASSERT_EQ(s.decode(encoded, 4), expected);
  return 0;
}
