/*
 * @lc app=leetcode id=20 lang=rust
 *
 * [20] Valid Parentheses
 */

struct Solution;

// @lc code=start
impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut stack = vec![];
        for c in s.chars() {
            if c == '(' || c == '{' || c == '[' {
                stack.push(c);
                continue;
            }

            match stack.pop() {
                Some(last) => {
                    if (last == '(' && c == ')')
                        || (last == '{' && c == '}')
                        || (last == '[' && c == ']')
                    {
                        continue;
                    }
                    return false;
                }
                None => return false,
            }
        }
        stack.is_empty()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_valid("()".to_string()));
    assert!(Solution::is_valid("()[]{}".to_string()));
    assert!(Solution::is_valid("{[]}".to_string()));
}

#[test]
fn test2() {
    assert!(!Solution::is_valid("(]".to_string()));
    assert!(!Solution::is_valid("([)]".to_string()));
}
