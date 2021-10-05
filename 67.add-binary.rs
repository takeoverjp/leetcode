/*
 * @lc app=leetcode id=67 lang=rust
 *
 * [67] Add Binary
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut a_val: u128 = 0;
        let mut b_val: u128 = 0;
        for c in a.chars() {
            a_val = (a_val << 1) + (if c == '1' { 1 } else { 0 });
        }
        for c in b.chars() {
            b_val = (b_val << 1) + (if c == '1' { 1 } else { 0 });
        }
        format!("{:b}", a_val + b_val)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::add_binary("11".to_string(), "1".to_string()),
        "100"
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::add_binary("1010".to_string(), "1011".to_string()),
        "10101"
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::add_binary("10100000100100110110010000010101111011011001101110111111111101000000101111001110001111100001101".to_string(), 
        "110101001011101110001111100110001010100001101011101010000011011011001011101111001100000011011110011".to_string()),
        "110111101100010011000101110110100000011101000101011001000011011000001100011110011010010011000000000");
}
