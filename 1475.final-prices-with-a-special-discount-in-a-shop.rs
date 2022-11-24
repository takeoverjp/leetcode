/*
 * @lc app=leetcode id=1475 lang=rust
 *
 * [1475] Final Prices With a Special Discount in a Shop
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
    pub fn final_prices(mut prices: Vec<i32>) -> Vec<i32> {
        let mut s = Vec::<i32>::new();
        for i in (0..prices.len()).rev() {
            while !s.is_empty() && s[s.len() - 1] > prices[i] {
                s.pop();
            }
            let x = prices[i];
            if !s.is_empty() {
                prices[i] -= s[s.len() - 1];
            }
            s.push(x);
        }
        prices
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::final_prices(vec![8, 4, 6, 2, 3]),
        vec![4, 2, 4, 2, 3]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::final_prices(vec![1, 2, 3, 4, 5]),
        vec![1, 2, 3, 4, 5]
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::final_prices(vec![10, 1, 1, 6]), vec![9, 0, 1, 6]);
}
