/*
 * @lc app=leetcode id=26 lang=rust
 *
 * [26] Remove Duplicates from Sorted Array
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() < 2 {
            return nums.len() as i32;
        }
        let mut idx = 1;
        for i in 1..nums.len() {
            if nums[i] != nums[i - 1] {
                nums[idx] = nums[i];
                idx += 1;
            }
        }
        idx as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut nums = vec![1, 1, 2];
    let exp = vec![1, 2];
    assert_eq!(Solution::remove_duplicates(&mut nums), 2);
    for i in 0..exp.len() {
        assert_eq!(nums[i], exp[i]);
    }
}

#[test]
fn test2() {
    let mut nums = vec![0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
    let exp = vec![0, 1, 2, 3, 4];
    assert_eq!(Solution::remove_duplicates(&mut nums), 5);
    for i in 0..exp.len() {
        assert_eq!(nums[i], exp[i]);
    }
}
