/*
 * @lc app=leetcode id=1403 lang=cpp
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
 */

#include <bits/stdc++.h>
#include "lassert/lassert.h"

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> minSubsequence(vector<int>& nums) {
    std::sort(nums.begin(), nums.end(),
              [](const auto lhs, const auto rhs) { return lhs > rhs; });
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    std::vector<int> ret;
    int sum = 0;
    for (const auto num : nums) {
      sum += num;
      ret.push_back(num);
      if (sum * 2 > total) {
        break;
      }
    }
    return ret;
  }
};
// @lc code=end

int main() {
  Solution s;
  vector<int> nums, exp;
  nums = {4, 3, 10, 9, 8};
  exp = {10, 9};
  ASSERT_EQ(s.minSubsequence(nums), exp);
  nums = {4, 3, 10, 9, 8, 3};
  exp = {10, 9};
  ASSERT_EQ(s.minSubsequence(nums), exp);
  nums = {4, 3, 10, 9, 8, 4};
  exp = {10, 9, 8};
  ASSERT_EQ(s.minSubsequence(nums), exp);
  nums = {4, 4, 7, 6, 7};
  exp = {7, 7, 6};
  ASSERT_EQ(s.minSubsequence(nums), exp);
  nums = {6};
  exp = {6};
  ASSERT_EQ(s.minSubsequence(nums), exp);
  nums = {
      46, 78,  51, 66, 73,  86, 22,  42,  68, 10, 81, 97,  7,   2,  74,  39, 13,
      58, 12,  1,  85, 7,   95, 36,  71,  40, 76, 80, 98,  33,  59, 50,  16, 83,
      29, 40,  83, 86, 100, 17, 66,  65,  96, 4,  47, 91,  58,  13, 56,  87, 20,
      36, 15,  48, 33, 98,  28, 43,  80,  19, 72, 29, 79,  1,   30, 91,  62, 46,
      83, 17,  53, 86, 44,  55, 80,  57,  15, 33, 7,  68,  38,  92, 66,  41, 26,
      27, 30,  95, 31, 49,  45, 33,  1,   63, 99, 65, 18,  55,  98, 62,  12, 67,
      36, 13,  29, 14, 55,  52, 19,  15,  86, 57, 67, 86,  28,  21, 28,  35, 47,
      91, 42,  45, 96, 33,  73, 97,  20,  4,  29, 33, 62,  100, 77, 69,  3,  44,
      3,  23,  90, 26, 34,  83, 30,  10,  55, 89, 48, 89,  48,  97, 99,  25, 14,
      1,  51,  44, 74, 43,  88, 53,  44,  76, 89, 33, 52,  97,  79, 36,  99, 46,
      79, 10,  56, 29, 79,  61, 45,  99,  37, 92, 4,  14,  77,  68, 7,   22, 80,
      97, 29,  99, 69, 57,  38, 55,  52,  80, 1,  9,  51,  20,  94, 76,  27, 61,
      86, 51,  64, 13, 53,  83, 22,  92,  85, 64, 28, 84,  40,  72, 100, 5,  39,
      38, 18,  33, 83, 66,  39, 61,  18,  56, 43, 67, 42,  27,  36, 6,   40, 65,
      74, 38,  64, 39, 34,  21, 38,  34,  43, 20, 34, 50,  87,  57, 85,  64, 93,
      22, 50,  6,  12, 75,  27, 41,  7,   67, 96, 40, 6,   54,  14, 80,  81, 90,
      42, 17,  2,  45, 31,  80, 46,  67,  56, 92, 31, 67,  11,  5,  43,  3,  84,
      57, 4,   22, 96, 36,  86, 79,  27,  55, 38, 81, 22,  6,   5,  64,  50, 70,
      88, 85,  15, 49, 37,  56, 7,   30,  43, 54, 76, 74,  63,  77, 27,  75, 66,
      87, 12,  44, 82, 52,  84, 23,  100, 31, 67, 63, 10,  82,  54, 87,  51, 28,
      33, 100, 1,  37, 5,   34, 100, 11,  24, 80, 33, 97,  58,  89, 56,  40, 13,
      39, 7,   62, 23, 33,  71, 27,  17,  6,  87, 52, 71,  2,   73, 65,  39, 1,
      94, 49,  44, 13, 33,  21, 77,  90,  26, 10, 23, 100, 90,  88, 74,  83, 49,
      68, 73,  93, 3,  29,  52, 88,  3,   86, 1,  68, 54,  98,  79, 99,  23, 7,
      95, 100, 51, 84, 54,  25, 21,  29,  12, 79, 58, 70,  70};
  exp = {100, 100, 100, 100, 100, 100, 100, 100, 99, 99, 99, 99, 99, 99, 98, 98,
         98,  98,  97,  97,  97,  97,  97,  97,  96, 96, 96, 96, 95, 95, 95, 94,
         94,  93,  93,  92,  92,  92,  92,  91,  91, 91, 90, 90, 90, 90, 89, 89,
         89,  89,  88,  88,  88,  88,  87,  87,  87, 87, 87, 86, 86, 86, 86, 86,
         86,  86,  86,  85,  85,  85,  85,  84,  84, 84, 84, 83, 83, 83, 83, 83,
         83,  83,  82,  82,  81,  81,  81,  80,  80, 80, 80, 80, 80, 80, 80, 79,
         79,  79,  79,  79,  79,  79,  78,  77,  77, 77, 77, 76, 76, 76, 76, 75,
         75,  74,  74,  74,  74,  74,  73,  73,  73, 73, 72, 72};
  ASSERT_EQ(s.minSubsequence(nums), exp);

  return 0;
}
