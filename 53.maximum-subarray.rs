/*
 * @lc app=leetcode id=53 lang=rust
 *
 * [53] Maximum Subarray
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn max_sub_array(nums: Vec<i32>) -> i32 {
        // Kadane's Algorythm
        let (mut current_max, mut global_max) = (nums[0], nums[0]);
        for num in nums.iter().skip(1) {
            let num = *num;
            current_max = std::cmp::max(num, current_max + num);
            global_max = global_max.max(current_max);
        }
        global_max
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4]),
        6
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::max_sub_array(vec![1]), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::max_sub_array(vec![5, 4, -1, 7, 8]), 23);
}
