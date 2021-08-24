/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n) {
            product *= n % 10;
            sum += n % 10;
            n /= 10;
        }
        return product - sum;
    }
};
// @lc code=end

int
main () {
  Solution s;
  ASSERT_EQ(s.subtractProductAndSum(234), 15);
  ASSERT_EQ(s.subtractProductAndSum(4421), 21);
  return 0;
}
