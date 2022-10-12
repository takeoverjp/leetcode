/*
 * @lc app=leetcode id=1281 lang=rust
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
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
    pub fn subtract_product_and_sum(mut n: i32) -> i32 {
        let mut sum = 0;
        let mut product = 1;
        while n > 0 {
            sum += n % 10;
            product *= n % 10;
            n /= 10;
        }
        product - sum
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::subtract_product_and_sum(234), 15);
}

#[test]
fn test2() {
    assert_eq!(Solution::subtract_product_and_sum(4421), 21);
}
