/*
 * @lc app=leetcode id=58 lang=rust
 *
 * [58] Length of Last Word
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        s.split_ascii_whitespace().last().unwrap().len() as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::length_of_last_word("Hello World".to_string()), 5);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::length_of_last_word("   fly me   to   the moon  ".to_string()),
        4
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::length_of_last_word("luffy is still joyboy".to_string()),
        6
    );
}
