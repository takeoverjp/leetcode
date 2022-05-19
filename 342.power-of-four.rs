/*
 * @lc app=leetcode id=342 lang=rust
 *
 * [342] Power of Four
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
    pub fn is_power_of_four(n: i32) -> bool {
        if n == 1 {
            return true;
        } else if n <= 0 || n % 4 != 0 {
            return false;
        }
        Solution::is_power_of_four(n / 4)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_power_of_four(16));
}

#[test]
fn test2() {
    assert!(!Solution::is_power_of_four(5));
}

#[test]
fn test3() {
    assert!(Solution::is_power_of_four(1));
}
