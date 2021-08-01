/*
 * @lc app=leetcode id=1175 lang=cpp
 *
 * [1175] Prime Arrangements
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int numPrimeArrangements(int n) {
    int pnum = prime_num(n);
    // cout << "pnum = " << pnum << endl;
    return factorial(n - pnum) * factorial(pnum) % (1000000007);
  }

 private:
  int prime_num(int n) {
    int ret = 0;
    int max = std::sqrt(n);
    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= max && j < i; j++) {
        if (i % j == 0) {
          goto NEXT;
        }
      }
      ret++;
    NEXT:;
    }
    return ret;
  }
  int64_t factorial(int n) {
    if (n <= 1) {
      return 1;
    }
    return (n * factorial(n - 1)) % 1000000007;
  }
};
// @lc code=end
int main() {
  Solution s;
  ASSERT_EQ(s.numPrimeArrangements(1), 1);
  ASSERT_EQ(s.numPrimeArrangements(2), 1);
  ASSERT_EQ(s.numPrimeArrangements(5), 12);
  ASSERT_EQ(s.numPrimeArrangements(11), 86400);
  ASSERT_EQ(s.numPrimeArrangements(100), 682289015);
  return 0;
}
