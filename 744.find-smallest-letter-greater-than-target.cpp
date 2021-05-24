/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    if (target < letters[0]) {
      return letters[0];
    }
    for (const auto letter : letters) {
      if (letter > target) {
        return letter;
      }
    }
    return letters[0];
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<char> letters;
  letters = {'c', 'f', 'j'};
  ASSERT_EQ(s.nextGreatestLetter(letters, 'a'), 'c');
  ASSERT_EQ(s.nextGreatestLetter(letters, 'c'), 'f');
  ASSERT_EQ(s.nextGreatestLetter(letters, 'd'), 'f');
  ASSERT_EQ(s.nextGreatestLetter(letters, 'g'), 'j');
  ASSERT_EQ(s.nextGreatestLetter(letters, 'k'), 'c');
  return 0;
}
