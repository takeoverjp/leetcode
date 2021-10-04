/*
 * @lc app=leetcode id=66 lang=rust
 *
 * [66] Plus One
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
        let mut need_carry_over = false;
        for (idx, digit) in digits.iter_mut().enumerate().rev() {
            if *digit < 9 {
                *digit += 1;
                break;
            }
            *digit = 0;
            if idx == 0 {
                need_carry_over = true;
            }
        }

        if need_carry_over {
            digits.insert(0, 1);
        }

        digits
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::plus_one(vec! {1,2,3}), vec! {1,2,4});
}

#[test]
fn test2() {
    assert_eq!(Solution::plus_one(vec! {4,3,2,1}), vec! {4,3,2,2});
}
#[test]
fn test3() {
    assert_eq!(Solution::plus_one(vec! {0}), vec! {1});
}

#[test]
fn test4() {
    assert_eq!(Solution::plus_one(vec! {9}), vec! {1,0});
}
