/*
 * @lc app=leetcode id=925 lang=rust
 *
 * [925] Long Pressed Name
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
    pub fn is_long_pressed_name(name: String, typed: String) -> bool {
        let nb = name.as_bytes();
        let mut i = 0;
        for &b in typed.as_bytes() {
            if i < name.len() && b == nb[i] {
                i += 1;
            } else if b != nb[i.saturating_sub(1)] {
                return false;
            }
        }
        i == name.len()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_long_pressed_name(
        "alex".to_string(),
        "aaleex".to_string()
    ));
}

#[test]
fn test2() {
    assert!(!Solution::is_long_pressed_name(
        "saeed".to_string(),
        "ssaaedd".to_string()
    ));
}

#[test]
fn test3() {
    assert!(!Solution::is_long_pressed_name(
        "a".to_string(),
        "b".to_string()
    ));
}
