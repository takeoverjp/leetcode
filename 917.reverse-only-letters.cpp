/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

// @lc code=start
class Solution {
 public:
  string reverseOnlyLetters(string s) {
    int len = s.length();
    int start = 0;
    int end = len - 1;
    while (start < end) {
      char start_c = 0;
      char end_c = 0;
      for (int i = start; i < end; i++) {
        if (isalpha(s[i])) {
          start_c = s[i];
          start = i;
          break;
        }
      }
      if (start_c == 0) {
        break;
      }
      for (int j = end; j > start; j--) {
        if (isalpha(s[j])) {
          end_c = s[j];
          end = j;
          break;
        }
      }
      if (end_c == 0) {
        break;
      }
      s[end] = start_c;
      s[start] = end_c;
      start++;
      end--;
    }
    return s;
  }
};
// @lc code=end
