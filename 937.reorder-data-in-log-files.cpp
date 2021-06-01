/*
 * @lc app=leetcode id=937 lang=cpp
 *
 * [937] Reorder Data in Log Files
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    std::sort(logs.begin(), logs.end()), [](auto const &lhs, auto const &rhs) {
      if (is_letter_log(lhs)) {
        if (is_letter_log(rhs)) {
          if (body(lhs) == body(rhs)) {
            return lhs > rhs;
          } else {
            return body(lhs) > body(rhs);
          }
        } else {
          return true;
        }
      } else {
        if (is_letter_log(rhs)) {
          return false;
        } else {
          return lhs > rhs;
        }
      }
    };
  }
  private:
  static std::string body(const std::string& log) {
    // TODO
    return log;
  }
  static bool is_letter_log(const std::string& log) {
    // TODO
    return false;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> logs, exp;
  logs = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig",
          "let3 art zero"};
  exp = {"let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1",
         "dig2 3 6"};
  ASSERT_EQ(s.reorderLogFiles(logs), exp);
  logs = {"a1 9 2 3 1", "g1 act car", "zo4 4 7", "ab1 off key dog",
          "a8 act zoo"};
  exp = {"g1 act car", "a8 act zoo", "ab1 off key dog", "a1 9 2 3 1",
         "zo4 4 7"};
  ASSERT_EQ(s.reorderLogFiles(logs), exp);
  return 0;
}
