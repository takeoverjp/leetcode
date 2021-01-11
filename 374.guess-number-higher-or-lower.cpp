/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    int first = 1;
    int end = n;
    while (true) {
      int64_t candidate = ((int64_t)first + (int64_t)end) / 2;
      int ret = guess(candidate);
      if (ret == 0) {
        return candidate;
      }

      if (ret < 0) {
        end = candidate - 1;
      } else {
        first = candidate + 1;
      }
    }
  }
};
// @lc code=end
