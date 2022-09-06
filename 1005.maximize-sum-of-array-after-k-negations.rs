/*
 * @lc app=leetcode id=1005 lang=rust
 *
 * [1005] Maximize Sum Of Array After K Negations
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

use std::cmp::Reverse;
use std::collections::BinaryHeap;
impl Solution {
    pub fn largest_sum_after_k_negations(nums: Vec<i32>, mut k: i32) -> i32 {
        let mut pq = BinaryHeap::new();
        for num in &nums {
            pq.push(Reverse(*num));
        }
        while k > 0 {
            if let Some(Reverse(n)) = pq.pop() {
                pq.push(Reverse(-n));
            }
            k -= 1;
        }
        let mut sum = 0;
        for _ in 0..nums.len() {
            if let Some(Reverse(n)) = pq.pop() {
                sum += n
            }
        }
        sum
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::largest_sum_after_k_negations(vec![4, 2, 3], 1), 5);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::largest_sum_after_k_negations(vec![3, -1, 0, 2], 3),
        6
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::largest_sum_after_k_negations(vec![2, -3, -1, 5, -4], 2),
        13
    );
}
