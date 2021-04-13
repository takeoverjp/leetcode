/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countPrimeSetBits(int L, int R) {
    int count = 0;
    for (int i = L; i <= R; i++) {
      if (isPrime(countBit(i))) {
        count++;
      }
    }
    return count;
  }
  int countBit(int n) {
    int count = 0;
    while (n) {
      count += n % 2;
      n >>= 1;
    }
    return count;
  }
  bool isPrime(int n) {
    if (n <= 1) {
      return false;
    }
    int sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.isPrime(1), false);
  ASSERT_EQ(s.isPrime(2), true);
  ASSERT_EQ(s.isPrime(3), true);
  ASSERT_EQ(s.isPrime(4), false);
  ASSERT_EQ(s.countBit(6), 2);
  ASSERT_EQ(s.countBit(7), 3);
  ASSERT_EQ(s.countBit(8), 1);
  ASSERT_EQ(s.countBit(9), 2);
  ASSERT_EQ(s.countBit(10), 2);
  ASSERT_EQ(s.countBit(11), 3);
  ASSERT_EQ(s.countBit(12), 2);
  ASSERT_EQ(s.countBit(13), 3);
  ASSERT_EQ(s.countBit(14), 3);
  ASSERT_EQ(s.countBit(15), 4);
  ASSERT_EQ(s.countBit(16), 1);
  ASSERT_EQ(s.countPrimeSetBits(6, 6), 1);
  ASSERT_EQ(s.countPrimeSetBits(15, 15), 0);
  ASSERT_EQ(s.countPrimeSetBits(6, 10), 4);
  ASSERT_EQ(s.countPrimeSetBits(10, 15), 5);
  return 0;
}
