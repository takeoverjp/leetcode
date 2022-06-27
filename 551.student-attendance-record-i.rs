/*
 * @lc app=leetcode id=551 lang=rust
 *
 * [551] Student Attendance Record I
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
    pub fn check_record(s: String) -> bool {
        let mut abs_num = 0;
        let mut cont_late_num = 0;
        for c in s.chars() {
            if c == 'L' {
                cont_late_num += 1;
            } else {
                cont_late_num = 0;
            }
            if c == 'A' {
                abs_num += 1;
            }
            if cont_late_num > 2 || abs_num > 1 {
                return false;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::check_record("PPALLP".to_string()));
}

#[test]
fn test2() {
    assert!(!Solution::check_record("PPALLL".to_string()));
}
