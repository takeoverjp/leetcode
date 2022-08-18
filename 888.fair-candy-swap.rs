/*
 * @lc app=leetcode id=888 lang=rust
 *
 * [888] Fair Candy Swap
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
    pub fn fair_candy_swap(alice_sizes: Vec<i32>, bob_sizes: Vec<i32>) -> Vec<i32> {
        let sum_a: i32 = alice_sizes.iter().sum();
        let sum_b: i32 = bob_sizes.iter().sum();
        let diff = (sum_a - sum_b) / 2;
        let set_b: std::collections::HashSet<i32> = bob_sizes.iter().cloned().collect();
        for alice_size in alice_sizes {
            if set_b.contains(&(alice_size - diff)) {
                return vec![alice_size, alice_size - diff];
            }
        }
        vec![-1, -1]
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::fair_candy_swap(vec![1, 1], vec![2, 2]),
        vec![1, 2]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::fair_candy_swap(vec![1, 2], vec![2, 3]),
        vec![1, 2]
    );
    assert_eq!(Solution::fair_candy_swap(vec![2], vec![1, 3]), vec![2, 3]);
}
