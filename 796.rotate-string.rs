/*
 * @lc app=leetcode id=796 lang=rust
 *
 * [796] Rotate String
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
    pub fn rotate_string(s: String, goal: String) -> bool {
        let len = s.len();
        if len != goal.len() {
            return false;
        }
        if len == 0 {
            return true;
        }
        let s = s.chars().collect::<Vec<char>>();
        let goal = goal.chars().collect::<Vec<char>>();
        for i in 0..len {
            let mut found = true;
            for j in 0..len {
                if s[j] != goal[(i + j) % len] {
                    found = false;
                    break;
                }
            }
            if found {
                return true;
            }
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::rotate_string(
        "abcde".to_string(),
        "cdeab".to_string()
    ));
}

#[test]
fn test2() {
    assert!(!Solution::rotate_string(
        "abcde".to_string(),
        "abced".to_string()
    ));
}
