/*
 * @lc app=leetcode id=263 lang=rust
 *
 * [263] Ugly Number
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
    pub fn is_ugly(n: i32) -> bool {
        if n == 0 {
            return false;
        }
        let mut n = n;
        while n % 5 == 0 {
            n /= 5;
        }
        while n % 3 == 0 {
            n /= 3;
        }
        while n % 2 == 0 {
            n /= 2;
        }
        n == 1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_ugly(6));
}

#[test]
fn test2() {
    assert!(Solution::is_ugly(1));
}

#[test]
fn test3() {
    assert!(!Solution::is_ugly(14));
}
