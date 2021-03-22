/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int calPoints(vector<string>& ops) {
    int size = ops.size();
    vector<int> work(size);
    int last_idx = 0;
    for (int i = 0; i < size; i++) {
      if (ops[i] == "C") {
        work[last_idx - 1] = 0;
        last_idx--;
      } else if (ops[i] == "D") {
        work[last_idx] = work[last_idx - 1] * 2;
        last_idx++;
      } else if (ops[i] == "+") {
        work[last_idx] = work[last_idx - 1] + work[last_idx - 2];
        last_idx++;
      } else {
        work[last_idx] = stoi(ops[i]);
        last_idx++;
      }
    }

    int sum = 0;
    for (const auto i : work) {
      sum += i;
    }
    return sum;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> ops;
  ops = {"5", "2", "C", "D", "+"};
  ASSERT_EQ(s.calPoints(ops), 30);
  ops = {"5", "-2", "4", "C", "D", "9", "+", "+"};
  ASSERT_EQ(s.calPoints(ops), 27);
  ops = {"1"};
  ASSERT_EQ(s.calPoints(ops), 1);
  ops = {"36","28","70","65","C","+","33","-46","84","C"};
  ASSERT_EQ(s.calPoints(ops), 219);
  return 0;
}
