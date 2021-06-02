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
    vector<string> digit_logs, ans;
    vector<pair<string, string>> letter_logs;
    for (const string &log : logs) {
      int offset = 0;
      while (!isspace(log[offset++])) {
      }
      if (isalpha(log[offset])) {
        letter_logs.emplace_back(log.substr(0, offset),
                                 log.substr(offset, log.length() - offset));
      } else {
        digit_logs.emplace_back(log);
      }
    }
    std::sort(letter_logs.begin(), letter_logs.end(),
              [](auto const &lhs, auto const &rhs) {
                if (lhs.second == rhs.second) {
                  return lhs.first < rhs.first;
                }
                return lhs.second < rhs.second;
              });
    for (const auto &log : letter_logs) {
      ans.emplace_back(log.first + log.second);
    }
    for (const auto &log : digit_logs) {
      ans.emplace_back(log);
    }
    return ans;
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

  logs = {"1 n u", "r 527", "j 893", "6 14", "6 82"};
  exp = {"1 n u", "r 527", "j 893", "6 14", "6 82"};
  ASSERT_EQ(s.reorderLogFiles(logs), exp);

  logs = {
      "l5sh 6 3869 08 1295",  "16o 94884717383724 9", "43 490972281212 3 51",
      "9 ehyjki ngcoobi mi",  "2epy 85881033085988",  "7z fqkbxxqfks f y dg",
      "9h4p 5 791738 954209", "p i hz uubk id s m l", "wd lfqgmu pvklkdp u",
      "m4jl 225084707500464", "6np2 bqrrqt q vtap h", "e mpgfn bfkylg zewmg",
      "ttzoz 035658365825 9", "k5pkn 88312912782538", "ry9 8231674347096 00",
      "w 831 74626 07 353 9", "bxao armngjllmvqwn q", "0uoj 9 8896814034171",
      "0 81650258784962331",  "t3df gjjn nxbrryos b"};
  exp = {"bxao armngjllmvqwn q", "6np2 bqrrqt q vtap h", "9 ehyjki ngcoobi mi",
         "7z fqkbxxqfks f y dg", "t3df gjjn nxbrryos b", "p i hz uubk id s m l",
         "wd lfqgmu pvklkdp u",  "e mpgfn bfkylg zewmg", "l5sh 6 3869 08 1295",
         "16o 94884717383724 9", "43 490972281212 3 51", "2epy 85881033085988",
         "9h4p 5 791738 954209", "m4jl 225084707500464", "ttzoz 035658365825 9",
         "k5pkn 88312912782538", "ry9 8231674347096 00", "w 831 74626 07 353 9",
         "0uoj 9 8896814034171", "0 81650258784962331"};
  ASSERT_EQ(s.reorderLogFiles(logs), exp);

  return 0;
}
