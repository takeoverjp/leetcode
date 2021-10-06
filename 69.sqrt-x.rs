/*
 * @lc app=leetcode id=69 lang=rust
 *
 * [69] Sqrt(x)
 */

struct Solution;

// @lc code=start
use std::cmp::Ordering;

impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x == 0 {
            return 0;
        }
        let mut left = 1;
        let mut right = 46341; // ceil(sqrt(i32.MAX))
        let x: i64 = x.into();
        loop {
            let mid: i64 = (left + right) / 2;
            let pow: i64 = mid * mid;
            match x.cmp(&pow) {
                Ordering::Greater => {
                    if (mid + 1) * (mid + 1) > x {
                        return mid as i32;
                    }
                    left = mid + 1;
                }
                Ordering::Less => {
                    right = mid - 1;
                }
                Ordering::Equal => {
                    return mid as i32;
                }
            }
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::my_sqrt(4), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::my_sqrt(8), 2);
}

#[test]
fn test3() {
    assert_eq!(Solution::my_sqrt(2147395600), 46340);
}

#[test]
fn test4() {
    assert_eq!(Solution::my_sqrt(2147483647), 46340);
}
