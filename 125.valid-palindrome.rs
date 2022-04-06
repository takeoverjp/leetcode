/*
 * @lc app=leetcode id=125 lang=rust
 *
 * [125] Valid Palindrome
 */

struct Solution;

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

#[macro_export]
macro_rules! list_node {
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let mut target = s.to_ascii_lowercase();
        target.retain(|c| ('a'..='z').contains(&c) || ('0'..='9').contains(&c));
        let len = target.len();
        for i in 0usize..(len / 2) {
            if target.as_bytes()[i] != target.as_bytes()[len - 1 - i] {
                return false;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_palindrome(
        "A man, a plan, a canal: Panama".to_string()
    ));
}

#[test]
fn test2() {
    assert!(!Solution::is_palindrome("race a car".to_string()));
}

#[test]
fn test3() {
    assert!(Solution::is_palindrome(" ".to_string()));
}

#[test]
fn test4() {
    assert!(!Solution::is_palindrome("0P".to_string()));
}
