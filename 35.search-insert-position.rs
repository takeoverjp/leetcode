/*
 * @lc app=leetcode id=35 lang=rust
 *
 * [35] Search Insert Position
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut start = 0;
        let mut end = nums.len() - 1;
        while end > start {
            if nums[start] == target {
                return start as i32;
            } else if nums[end] == target {
                return end as i32;
            } else if nums[start] > target {
                return start as i32;
            } else if nums[end] < target {
                return (end + 1) as i32;
            }
            let mid = (start + end) / 2;
            if nums[mid] < target {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        if nums[start] < target {
            start += 1;
        }
        start as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::search_insert(vec!(1, 3, 5, 6), 5), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::search_insert(vec!(1, 3, 5, 6), 2), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::search_insert(vec!(1, 3, 5, 6), 7), 4);
}

#[test]
fn test4() {
    assert_eq!(Solution::search_insert(vec!(1, 3, 5, 6), 0), 0);
}

#[test]
fn test5() {
    assert_eq!(Solution::search_insert(vec!(1), 0), 0);
}
