/*
 * @lc app=leetcode id=13 lang=rust
 *
 * [13] Roman to Integer
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut sum: i32 = 0;
        for (i, c) in s.chars().enumerate() {
            let n = s.chars().nth(i + 1).unwrap_or('.');
            match c {
                'I' => {
                    if n == 'V' || n == 'X' {
                        sum -= 1;
                    } else {
                        sum += 1;
                    }
                }
                'V' => {
                    sum += 5;
                }
                'X' => {
                    if n == 'L' || n == 'C' {
                        sum -= 10;
                    } else {
                        sum += 10;
                    }
                }
                'L' => {
                    sum += 50;
                }
                'C' => {
                    if n == 'D' || n == 'M' {
                        sum -= 100;
                    } else {
                        sum += 100;
                    }
                }
                'D' => {
                    sum += 500;
                }
                'M' => {
                    sum += 1000;
                }
                _ => {}
            }
        }
        sum
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::roman_to_int("III".to_string()), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::roman_to_int("IV".to_string()), 4);
}
#[test]
fn test3() {
    assert_eq!(Solution::roman_to_int("IX".to_string()), 9);
}
#[test]
fn test4() {
    assert_eq!(Solution::roman_to_int("LVIII".to_string()), 58);
}
#[test]
fn test5() {
    assert_eq!(Solution::roman_to_int("MCMXCIV".to_string()), 1994);
}
