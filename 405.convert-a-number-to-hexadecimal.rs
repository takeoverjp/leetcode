/*
 * @lc app=leetcode id=405 lang=rust
 *
 * [405] Convert a Number to Hexadecimal
 */

// @lc code=start
impl Solution {
    pub fn to_hex(num: i32) -> String {
        let mut num = num as u32;
        if num == 0 {
            return "0".to_string();
        }
        let mut bytes = vec![];
        while num != 0 {
            let v = (num & 0xf) as u8;
            match v {
                0..=9 => bytes.push(b'0' + v),
                _ => bytes.push(b'a' + v - 10),
            }
            num >>= 4;
        }
        bytes.reverse();
        String::from_utf8(bytes).unwrap()
    }
}
// @lc code=end
