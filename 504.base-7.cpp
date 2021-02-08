/*
 * @lc app=leetcode id=504 lang=cpp
 *
 * [504] Base 7
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  string convertToBase7(int num) {
    string ret;
    bool is_negative = false;
    if (num < 0) {
      is_negative = true;
      num = -1 * num;
    }
    do {
      char char7[2] = {static_cast<char>('0' + num % 7), 0};
      ret = string(char7) + ret;
      num /= 7;

    } while (num);

    if (is_negative) {
      ret = "-" + ret;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.convertToBase7(100) == "202");
  assert(s.convertToBase7(-7) == "-10");
  assert(s.convertToBase7(0) == "0");

  return 0;
}
