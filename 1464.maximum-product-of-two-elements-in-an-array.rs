/*
 * @lc app=leetcode id=1464 lang=rust
 *
 * [1464] Maximum Product of Two Elements in an Array
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
    pub fn max_product(nums: Vec<i32>) -> i32 {
        let mut m1 = 0;
        let mut m2 = 0;
        for n in nums {
            if n > m1 {
                m2 = m1;
                m1 = n;
            } else {
                m2 = m2.max(n);
            }
        }
        (m1 - 1) * (m2 - 1)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::max_product(vec![3, 4, 5, 2]), 12);
}

#[test]
fn test2() {
    assert_eq!(Solution::max_product(vec![1, 5, 4, 5]), 16);
}

#[test]
fn test3() {
    assert_eq!(Solution::max_product(vec![3, 7]), 12);
}
