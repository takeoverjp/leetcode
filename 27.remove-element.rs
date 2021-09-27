/*
 * @lc app=leetcode id=27 lang=rust
 *
 * [27] Remove Element
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut count: i32 = 0;
        for num in nums.iter_mut() {
            if *num == val {
                *num = 51;
                count += 1;
            }
        }
        nums.sort_unstable();
        nums.len() as i32 - count
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut nums = vec![3, 2, 2, 3];
    let exp = vec![2, 2];
    assert_eq!(Solution::remove_element(&mut nums, 3), exp.len() as i32);
    for i in 0..exp.len() {
        assert_eq!(nums[i], exp[i]);
    }
}

#[test]
fn test2() {
    let mut nums = vec![0, 1, 2, 2, 3, 0, 4, 2];
    let exp = vec![0, 0, 1, 3, 4];
    assert_eq!(Solution::remove_element(&mut nums, 2), exp.len() as i32);
    for i in 0..exp.len() {
        assert_eq!(nums[i], exp[i]);
    }
}
