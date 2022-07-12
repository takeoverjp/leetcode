/*
 * @lc app=leetcode id=693 lang=rust
 *
 * [693] Binary Number with Alternating Bits
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
    pub fn has_alternating_bits(n: i32) -> bool {
        let u = n as u32;
        let mut state = u & 1;
        let mut index = 1;
        while (1u32 << index) < u {
            if ((u >> index) & 1) == state {
                return false;
            }
            index += 1;
            if state == 0 {
                state = 1;
            } else {
                state = 0;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::has_alternating_bits(5));
}

#[test]
fn test2() {
    assert!(!Solution::has_alternating_bits(7));
}

#[test]
fn test3() {
    assert!(!Solution::has_alternating_bits(11));
}
