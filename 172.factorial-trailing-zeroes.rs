/*
 * @lc app=leetcode id=172 lang=rust
 *
 * [172] Factorial Trailing Zeroes
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
    pub fn trailing_zeroes(mut n: i32) -> i32 {
        let mut ret = 0;
        while n > 0 {
            n /= 5;
            ret += n;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::trailing_zeroes(3), 0);
}

#[test]
fn test2() {
    assert_eq!(Solution::trailing_zeroes(5), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::trailing_zeroes(0), 0);
}
