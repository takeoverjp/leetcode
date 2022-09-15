/*
 * @lc app=leetcode id=1046 lang=rust
 *
 * [1046] Last Stone Weight
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
    pub fn last_stone_weight(stones: Vec<i32>) -> i32 {
        let mut pq = stones
            .into_iter()
            .collect::<std::collections::BinaryHeap<i32>>();
        while pq.len() > 1 {
            let y = pq.pop().unwrap();
            let x = pq.pop().unwrap();
            if x != y {
                pq.push(y - x);
            }
        }

        if pq.is_empty() {
            0
        } else {
            *pq.peek().unwrap()
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::last_stone_weight(vec![2, 7, 4, 1, 8, 1]), 1);
}

#[test]
fn test2() {
    assert_eq!(Solution::last_stone_weight(vec![1]), 1);
}
