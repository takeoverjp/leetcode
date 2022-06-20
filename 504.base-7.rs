/*
 * @lc app=leetcode id=504 lang=rust
 *
 * [504] Base 7
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
    pub fn convert_to_base7(mut num: i32) -> String {
        let mut ret = String::new();
        let mut is_negative = false;
        if num < 0 {
            is_negative = true;
            num = -num;
        }
        while {
            ret = format!("{}{}", num % 7, ret);
            num /= 7;
            num != 0
        } {}

        if is_negative {
            "-".to_string() + &ret
        } else {
            ret
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::convert_to_base7(100), "202".to_string());
}

#[test]
fn test2() {
    assert_eq!(Solution::convert_to_base7(-7), "-10".to_string());
}
