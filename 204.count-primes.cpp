/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    if (n <= 2) {
      return 0;
    }
    vector<bool> is_non_prime(n + 1);
    int sq = sqrt(n);
    for (int i = 2; i <= sq; i++) {
      if (is_non_prime[i]) continue;
      for (int j = i * 2; j < n; j += i) {
        is_non_prime[j] = true;
      }
    }
    int count = 1;
    for (int i = 3; i < n; i++) {
      if (!is_non_prime[i]) count++;
    }
    return count;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.countPrimes(0) == 0);
  assert(s.countPrimes(1) == 0);
  assert(s.countPrimes(2) == 0);
  assert(s.countPrimes(3) == 1);
  assert(s.countPrimes(4) == 2);
  assert(s.countPrimes(9) == 4);
  assert(s.countPrimes(10) == 4);
  return 0;
}
