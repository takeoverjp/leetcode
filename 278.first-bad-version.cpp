/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    return firstBadVersion(1, n);
  }

  private:
  int firstBadVersion(int start, int end) {
    int mid = ((int64_t)start + (int64_t)end) / 2;
    if (mid == start) {
      if (isBadVersion(mid)) {
        return start;
      } else {
        return end;
      }
    }
    if (isBadVersion(mid)) {
        return firstBadVersion(start, mid);
    } else {
        return firstBadVersion(mid, end);
    }
  }
};
// @lc code=end
