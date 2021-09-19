/*
 * @lc app=leetcode id=1 lang=rust
 *
 * [1] Two Sum
 */

struct Solution {}

// @lc code=start
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..nums.len() {
            for j in (i + 1)..nums.len() {
                if nums[i] + nums[j] == target {
                    return vec![i as i32, j as i32];
                }
            }
        }
        return vec![0, 0];
    }
}
// @lc code=end

#[test]
fn test1() {
    let v = vec![2, 7, 1, 5];
    assert_eq!(Solution::two_sum(v, 9), vec![0, 1]);
}

#[test]
fn test2() {
    let v = vec![3, 2, 4];
    assert_eq!(Solution::two_sum(v, 6), vec![1, 2]);
}

#[test]
fn test3() {
    let v = vec![3, 3];
    assert_eq!(Solution::two_sum(v, 6), vec![0, 1]);
}
