/*
 * @lc app=leetcode id=14 lang=rust
 *
 * [14] Longest Common Prefix
 */

use std::cmp::min;

struct Solution;
// @lc code=start
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut current = strs[0].len();
        for i in 1..strs.len() {
            current = min(current, strs[i].len());
            for j in 0..current {
                if strs[i - 1].chars().nth(j) != strs[i].chars().nth(j) {
                    current = j;
                    break;
                }
            }
            println!("current = {}", current);
        }
        strs[0].chars().collect::<Vec<char>>()[..current]
            .iter()
            .collect()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::longest_common_prefix(vec!(
            "flower".to_string(),
            "flow".to_string(),
            "flight".to_string()
        )),
        "fl"
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::longest_common_prefix(vec!(
            "dog".to_string(),
            "racecar".to_string(),
            "car".to_string()
        )),
        ""
    );
}
