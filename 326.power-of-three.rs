/*
 * @lc app=leetcode id=326 lang=rust
 *
 * [326] Power of Three
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
    pub fn is_power_of_three(n: i32) -> bool {
        match n {
            0 => false,
            1 => true,
            n if n % 3 != 0 => false,
            _ => Solution::is_power_of_three(n / 3),
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_power_of_three(27));
}

#[test]
fn test2() {
    assert!(!Solution::is_power_of_three(0));
}

#[test]
fn test3() {
    assert!(Solution::is_power_of_three(9));
}
