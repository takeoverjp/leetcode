/*
 * @lc app=leetcode id=628 lang=rust
 *
 * [628] Maximum Product of Three Numbers
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
    pub fn maximum_product(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let len = nums.len();
        std::cmp::max(
            nums[len - 1] * nums[len - 2] * nums[len - 3],
            nums[len - 1] * nums[0] * nums[1],
        )
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::maximum_product(vec![1, 2, 3]), 6);
}

#[test]
fn test2() {
    assert_eq!(Solution::maximum_product(vec![1, 2, 3, 4]), 24);
}

#[test]
fn test3() {
    assert_eq!(Solution::maximum_product(vec![-1, -2, -3]), -6);
}
