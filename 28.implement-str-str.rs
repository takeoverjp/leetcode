/*
 * @lc app=leetcode id=28 lang=rust
 *
 * [28] Implement strStr()
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let hlen = haystack.len();
        let nlen = needle.len();
        if needle.is_empty() {
            return 0;
        }
        if hlen < nlen {
            return -1;
        }
        for i in 0..(hlen - nlen + 1) {
            if haystack[i..i + nlen] == needle {
                return i as i32;
            }
        }
        -1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::str_str("hello".to_string(), "ll".to_string()), 2);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::str_str("aaaaa".to_string(), "bba".to_string()),
        -1
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::str_str("a".to_string(), "a".to_string()), 0);
    assert_eq!(Solution::str_str("".to_string(), "".to_string()), 0);
}
