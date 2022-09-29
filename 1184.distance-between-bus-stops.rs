/*
 * @lc app=leetcode id=1184 lang=rust
 *
 * [1184] Distance Between Bus Stops
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
    pub fn distance_between_bus_stops(
        distance: Vec<i32>,
        mut start: i32,
        mut destination: i32,
    ) -> i32 {
        let mut sum1 = 0;
        let mut sum2 = 0;
        if start > destination {
            std::mem::swap(&mut start, &mut destination);
        }
        for (i, d) in distance.iter().enumerate() {
            if i >= start as usize && i < destination as usize {
                sum1 += *d;
            } else {
                sum2 += *d;
            }
        }
        sum1.min(sum2)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 0, 1),
        1
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 0, 2),
        3
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 0, 3),
        4
    );
}
