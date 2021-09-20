/*
 * @lc app=leetcode id=7 lang=rust
 *
 * [7] Reverse Integer
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut x = x;
        let mut y: i32 = 0;
        while x != 0 {
            match y.checked_mul(10) {
                None => return 0,
                Some(i) => y = i,
            }
            match y.checked_add(x % 10) {
                None => return 0,
                Some(i) => y = i,
            }
            x /= 10;
        }
        y
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::reverse(123), 321);
}

#[test]
fn test2() {
    assert_eq!(Solution::reverse(-123), -321);
}

#[test]
fn test3() {
    assert_eq!(Solution::reverse(120), 21);
}

#[test]
fn test4() {
    assert_eq!(Solution::reverse(0), 0);
}

#[test]
fn test5() {
    assert_eq!(Solution::reverse(1534236469), 0);
}
