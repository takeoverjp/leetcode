/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  string defangIPaddr(string address) {
    int len = address.length();
    int dot_num = std::count(std::begin(address), std::end(address), '.');
    int new_len = len + 2 * dot_num;
    std::string ret;
    ret.reserve(new_len);
    for (int i = 0; i < len; i++) {
      if (address[i] == '.') {
        ret.push_back('[');
        ret.push_back('.');
        ret.push_back(']');
      } else {
        ret.push_back(address[i]);
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  ASSERT_EQ(s.defangIPaddr("1.1.1.1"), "1[.]1[.]1[.]1");
  ASSERT_EQ(s.defangIPaddr("255.100.50.0"), "255[.]100[.]50[.]0");
  return 0;
}
