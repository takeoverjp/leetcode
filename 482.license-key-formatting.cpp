/*
 * @lc app=leetcode id=482 lang=cpp
 *
 * [482] License Key Formatting
 */

#include <bits/stdc++.h>
#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  string licenseKeyFormatting(string S, int K) {
    string ret;
    int dash_num = 0;
    for (const char c : S) {
      if (c == '-') dash_num++;
    }
    int len = S.length() - dash_num;
    int part_len = (len - 1) % K + 1;
    // cout << len << "," << part_len << endl;

    for (char c : S) {
      if (c == '-') continue;
      if (part_len == 0) {
        ret += '-';
        part_len = K;
      }
      if (islower(c)) {
        c += 'A' - 'a';
      }
      ret += c;
      part_len--;
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.licenseKeyFormatting("5F3Z-2e-9-w", 4) == "5F3Z-2E9W");
  assert(s.licenseKeyFormatting("2-5g-3-J", 2) == "2-5G-3J");
  assert(s.licenseKeyFormatting("r", 1) == "R");
  assert(s.licenseKeyFormatting("12345abcde", 10) == "12345ABCDE");
  assert(s.licenseKeyFormatting("a0001afds-", 4) == "A-0001-AFDS");
  return 0;
}
