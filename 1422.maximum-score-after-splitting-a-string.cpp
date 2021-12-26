/*
 * @lc app=leetcode id=1422 lang=cpp
 *
 * [1422] Maximum Score After Splitting a String
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
public:
    int maxScore(string s) {
        int score = s[0] == '0';
        int size = s.size();
        for(int i = 1; i < size; i++) {
            if (s[i] == '1') {
                score++;
            }
        }
        int max_score = score;
        for(int i = 1; i < size - 1; i++) {
            if (s[i] == '1') {
                score--;
            } else {
                score++;
            }
            max_score = max(max_score, score);
        }
        return max_score;
    }
};
// @lc code=end

int
main () {
  Solution s;
  ASSERT_EQ(s.maxScore("011101"), 5);
  ASSERT_EQ(s.maxScore("00111"), 5);
  ASSERT_EQ(s.maxScore("1111"), 3);
  return 0;
}
