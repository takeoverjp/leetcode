/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    double average(vector<int>& salary) {
        int sum = accumulate(salary.begin(), salary.end(), 0);
        sum -= *max_element(salary.begin(), salary.end());
        sum -= *min_element(salary.begin(), salary.end());
        return (double)sum / (double)(salary.size() - 2);
    }
};
// @lc code=end

int
main () {
  Solution s;
  vector<int> salary;
  salary = {4000, 3000, 1000, 2000};
  ASSERT_EQ(s.average(salary), 2500.00000);
  salary = {1000, 2000, 3000};
  ASSERT_EQ(s.average(salary), 2000.00000);
  return 0;
}
