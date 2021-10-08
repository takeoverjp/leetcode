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
        let mut current_max: i64 = i32::MIN.into();
        let mut global_max: i64 = i32::MIN.into();
        for num in nums {
            let num: i64 = num.into();
            current_max = std::cmp::max(current_max + num, num);
            global_max = std::cmp::max(global_max, current_max);
        }
        global_max as i32
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
