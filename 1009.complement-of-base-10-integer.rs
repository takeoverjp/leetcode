/*
 * @lc app=leetcode id=1009 lang=rust
 *
 * [1009] Complement of Base 10 Integer
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
    pub fn bitwise_complement(n: i32) -> i32 {
        let mut c = 1;
        while c < n {
            c = (c << 1) + 1;
        }
        n ^ c
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::bitwise_complement(5), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::bitwise_complement(7), 0);
}

#[test]
fn test3() {
    assert_eq!(Solution::bitwise_complement(10), 5);
}
