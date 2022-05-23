/*
 * @lc app=leetcode id=350 lang=rust
 *
 * [350] Intersection of Two Arrays II
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
use std::collections::HashMap;
impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        let mut map = HashMap::new();
        for n in nums1 {
            *map.entry(n).or_insert(0) += 1;
        }
        let mut ret = Vec::new();
        for n in nums2 {
            if let Some(value) = map.get_mut(&n) {
                if *value > 0 {
                    ret.push(n as i32);
                    *value -= 1;
                }
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::intersect(vec![1, 2, 2, 1], vec![2, 2]),
        vec![2, 2]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::intersect(vec![4, 9, 5], vec![9, 4, 9, 8, 4]),
        vec![9, 4]
    );
}
