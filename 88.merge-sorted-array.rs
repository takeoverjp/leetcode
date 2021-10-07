/*
 * @lc app=leetcode id=88 lang=rust
 *
 * [88] Merge Sorted Array
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut i1 = m as usize;
        let mut i2 = n as usize;
        for i in (0..(m + n) as usize).rev() {
            if i1 == 0 {
                nums1[i] = nums2[i2 - 1];
                i2 -= 1;
            } else if i2 == 0 || nums1[i1 - 1] > nums2[i2 - 1] {
                nums1[i] = nums1[i1 - 1];
                i1 -= 1;
            } else {
                nums1[i] = nums2[i2 - 1];
                i2 -= 1;
            }
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut nums1 = vec![1, 2, 3, 0, 0, 0];
    let mut nums2 = vec![2, 5, 6];
    Solution::merge(&mut nums1, 3, &mut nums2, 3);
    assert_eq!(nums1, vec![1, 2, 2, 3, 5, 6]);
}

#[test]
fn test2() {
    let mut nums1 = vec![1];
    let mut nums2 = vec![];
    Solution::merge(&mut nums1, 1, &mut nums2, 0);
    assert_eq!(nums1, vec![1]);
}
