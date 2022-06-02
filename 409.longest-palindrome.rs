/*
 * @lc app=leetcode id=409 lang=rust
 *
 * [409] Longest Palindrome
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

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
    pub right: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

#[macro_export]
macro_rules! list_node {
    () => {
        None
    };
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut map = std::collections::HashMap::<char, i32>::new();
        let mut ret = 0;
        for c in s.chars() {
            let val = map.entry(c).or_insert(0);
            if *val == 0 {
                *val = 1;
            } else {
                map.remove(&c);
                ret += 2;
            }
        }
        if !map.is_empty() {
            ret += 1;
        }

        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::longest_palindrome("abccccdd".to_string()), 7);
}

#[test]
fn test2() {
    assert_eq!(Solution::longest_palindrome("a".to_string()), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::longest_palindrome("bb".to_string()), 2);
}
