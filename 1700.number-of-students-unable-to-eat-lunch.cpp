/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    int one_students = accumulate(begin(students), end(students), 0);
    int zero_students = students.size() - one_students;
    int one_sandwiches = accumulate(begin(sandwiches), end(sandwiches), 0);
    if (one_students == one_sandwiches) {
      return 0;
    }
    for (int i : sandwiches) {
      if (i) {
        if (!one_students) {
          return one_students + zero_students;
        }
        one_students--;
      } else {
        if (!zero_students) {
          return one_students + zero_students;
        }
        zero_students--;
      }
    }
    return 0;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> students, sandwitches;
  students = {1, 1, 0, 0};
  sandwitches = {0, 1, 0, 1};
  ASSERT_EQ(s.countStudents(students, sandwitches), 0);
  students = {1, 1, 1, 0, 0, 1};
  sandwitches = {1, 0, 0, 0, 1, 1};
  ASSERT_EQ(s.countStudents(students, sandwitches), 3);
  students = {0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1};
  sandwitches = {1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0};
  ASSERT_EQ(s.countStudents(students, sandwitches), 1);

  return 0;
}
