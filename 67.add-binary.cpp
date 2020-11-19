/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <alloca.h>
#include <bits/stdc++.h>

#include <cassert>

using namespace std;

// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    size_t a_len = a.length();
    size_t b_len = b.length();
    string ret;
    char carry = 0;
    for (uint32_t i = 1; i <= 10000; i++) {
      if (a_len < i && b_len < i && carry == 0) {
        break;
      }
      char a_val = (a_len >= i) ? (a[a_len - i] - '0') : 0;
      char b_val = (b_len >= i) ? (b[b_len - i] - '0') : 0;
      char sum = a_val + b_val + carry;
      carry = sum / 2;
      ret.insert(ret.begin(), (sum % 2) + '0');
    }
    cerr << "@@@" << ret << endl;
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  assert(s.addBinary("11", "1") == "100");
  assert(s.addBinary("1010", "1011") == "10101");
  assert(s.addBinary("0", "0") == "0");
  assert(s.addBinary("111", "111") == "1110");
  assert(s.addBinary(
             "111111111111111111111111111111111111111111111111111111111",
             "111111111111111111111111111111111111111111111111111111111") ==
         "1111111111111111111111111111111111111111111111111111111110");
  return 0;
}
