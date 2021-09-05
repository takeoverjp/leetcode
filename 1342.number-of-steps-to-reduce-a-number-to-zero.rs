/*
 * @lc app=leetcode id=1342 lang=rust
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
impl Solution {
    pub fn number_of_steps(num: i32) -> i32 {
        let mut ret = 0;
        let mut num = num;
        while (num > 0) {
            if num % 2 == 1 {
                num -= 1;
            } else {
                num /= 2;
            }
            ret += 1;
        }
        ret
    }
}
// @lc code=end
