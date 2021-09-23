/*
 * @lc app=leetcode id=14 lang=rust
 *
 * [14] Longest Common Prefix
 */

struct Solution;
// @lc code=start
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut longest_prefix = strs[0].len();
        for i in 1..strs.len() {
            longest_prefix = std::cmp::min(longest_prefix, strs[i].len());
            let cmp_end = longest_prefix;
            for j in 0..cmp_end {
                if strs[i - 1].chars().nth(j) != strs[i].chars().nth(j) {
                    longest_prefix = j;
                    break;
                }
            }
        }
        strs[0].chars().collect::<Vec<char>>()[..longest_prefix]
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
