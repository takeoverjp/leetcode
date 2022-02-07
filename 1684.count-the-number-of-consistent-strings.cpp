/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    sort(begin(allowed), end(allowed));
    return count_if(begin(words), end(words), [&allowed](const auto& word) {
      for (const auto c : word) {
        if (!binary_search(begin(allowed), end(allowed), c)) {
          return false;
        }
      }
      return true;
    });
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<string> words;
  words = {"ad", "bd", "aaab", "baa", "badab"};
  ASSERT_EQ(s.countConsistentStrings("ab", words), 2);
  words = {"a", "b", "c", "ab", "ac", "bc", "abc"};
  ASSERT_EQ(s.countConsistentStrings("abc", words), 7);
  words = {"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
  ASSERT_EQ(s.countConsistentStrings("cad", words), 4);
  return 0;
}
