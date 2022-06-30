/*
 * @lc app=leetcode id=575 lang=rust
 *
 * [575] Distribute Candies
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
use std::collections::HashSet;
impl Solution {
    pub fn distribute_candies(candy_type: Vec<i32>) -> i32 {
        let len = candy_type.iter().collect::<HashSet<_>>().len() as i32;
        std::cmp::min(len, candy_type.len() as i32 / 2)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::distribute_candies(vec![1, 1, 2, 2, 3, 3]), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::distribute_candies(vec![1, 1, 2, 3]), 2);
}

#[test]
fn test3() {
    assert_eq!(Solution::distribute_candies(vec![6, 6, 6, 6]), 1);
}
