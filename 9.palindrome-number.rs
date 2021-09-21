/*
 * @lc app=leetcode id=9 lang=rust
 *
 * [9] Palindrome Number
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x == 0 {
            return true;
        }
        if x < 0 {
            return false;
        }
        let mut tmp = x;
        let mut y: u64 = 0;
        while tmp > 0 {
            y = y * 10 + tmp as u64 % 10;
            tmp /= 10;
        }
        x as u64 == y
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::is_palindrome(121), true);
}

#[test]
fn test2() {
    assert_eq!(Solution::is_palindrome(-121), false);
}

#[test]
fn test3() {
    assert_eq!(Solution::is_palindrome(10), false);
}

#[test]
fn test4() {
    assert_eq!(Solution::is_palindrome(-101), false);
}
