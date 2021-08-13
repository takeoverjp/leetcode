#
# @lc app=leetcode id=1 lang=python3
#
# [1] Two Sum
#

import unittest
from typing import List


# @lc code=start
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(0, len(nums) - 1):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]

# @lc code=end


class TestSolution(unittest.TestCase):
    def setUp(self) -> None:
        self.sol = Solution()
        return super().setUp()

    def test_example1(self):
        self.assertEqual(self.sol.twoSum([2, 7, 11, 15], 9), [0, 1])

    def test_example2(self):
        self.assertEqual(self.sol.twoSum([3, 2, 4], 6), [1, 2])

    def test_example3(self):
        self.assertEqual(self.sol.twoSum([3, 3], 6), [0, 1])


if __name__ == '__main__':
    unittest.main()
