/*
 * @lc app=leetcode id=724 lang=rust
 *
 * [724] Find Pivot Index
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
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = -nums[0];
        let size = nums.len();
        for num in &nums {
            right += num;
        }
        if left == right {
            return 0;
        }
        for i in 1..size {
            left += nums[i - 1];
            right -= nums[i];
            if left == right {
                return i as i32;
            }
        }
        -1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::pivot_index(vec![1, 7, 3, 6, 5, 6]), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::pivot_index(vec![1, 2, 3]), -1);
}

#[test]
fn test3() {
    assert_eq!(Solution::pivot_index(vec![2, 1, -1]), 0);
}
