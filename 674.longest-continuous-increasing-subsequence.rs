/*
 * @lc app=leetcode id=674 lang=rust
 *
 * [674] Longest Continuous Increasing Subsequence
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
    pub fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size <= 1 {
            return size as i32;
        }
        let mut last = nums[0];
        let mut longest = 1;
        let mut current = 1;
        for num in nums.iter().skip(1) {
            if *num > last {
                current += 1;
                longest = longest.max(current);
            } else {
                current = 1;
            }
            last = *num;
        }
        longest
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_length_of_lcis(vec![1, 3, 5, 4, 7]), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_length_of_lcis(vec![2, 2, 2, 2, 2]), 1);
}
