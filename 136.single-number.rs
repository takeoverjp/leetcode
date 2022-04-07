/*
 * @lc app=leetcode id=136 lang=rust
 *
 * [136] Single Number
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

#[macro_export]
macro_rules! list_node {
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
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
    pub fn single_number(nums: Vec<i32>) -> i32 {
        let mut set = HashSet::new();
        for num in nums {
            if set.contains(&num) {
                set.remove(&num);
            } else {
                set.insert(num);
            }
        }
        if let Some(x) = set.iter().next() {
            return *x;
        }
        0
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::single_number(vec![2, 2, 1]), 1);
}

#[test]
fn test2() {
    assert_eq!(Solution::single_number(vec![4, 1, 2, 1, 2]), 4);
}

#[test]
fn test3() {
    assert_eq!(Solution::single_number(vec![1]), 1);
}
