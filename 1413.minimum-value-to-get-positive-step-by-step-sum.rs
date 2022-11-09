/*
 * @lc app=leetcode id=1413 lang=rust
 *
 * [1413] Minimum Value to Get Positive Step by Step Sum
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
    pub fn min_start_value(nums: Vec<i32>) -> i32 {
        let mut ans = 0;
        let mut sum = 0;
        for num in nums {
            sum += num;
            ans = ans.min(sum);
        }
        -ans + 1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::min_start_value(vec![-3, 2, -3, 4, 2]), 5);
}

#[test]
fn test2() {
    assert_eq!(Solution::min_start_value(vec![1, 2]), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::min_start_value(vec![1, -2, -3]), 5);
}
