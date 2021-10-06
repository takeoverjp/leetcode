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
        let x: i64 = x.into();
        for i in 0i32.. {
            let pow: i64 = (i as i64) * (i as i64);
            match x.cmp(&pow) {
                Ordering::Greater => {
                    continue;
                }
                Ordering::Equal => {
                    return i;
                }
                Ordering::Less => {
                    return i - 1;
                }
            }
        }
        -1
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
