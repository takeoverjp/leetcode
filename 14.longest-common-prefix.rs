/*
 * @lc app=leetcode id=14 lang=rust
 *
 * [14] Longest Common Prefix
 */

struct Solution;
// @lc code=start
impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut ret: Vec<char> = strs[0].chars().collect();
        for str in strs.iter().skip(1) {
            let cmp_end = ret.len();
            let curr: Vec<char> = str.chars().collect();
            let curr_len = curr.len();
            for j in 0..cmp_end {
                if j >= curr_len || ret[j] != curr[j] {
                    ret = ret[..j].to_vec();
                    break;
                }
            }
        }
        ret.iter().collect()
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
