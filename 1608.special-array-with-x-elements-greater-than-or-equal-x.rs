/*
 * @lc app=leetcode id=1608 lang=rust
 *
 * [1608] Special Array With X Elements Greater Than or Equal X
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
    pub fn special_array(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        nums.reverse();
        let mut start = 0;
        let mut end = nums.len();

        while start < end {
            let middle = (start + end) / 2;
            if middle < nums[middle] as usize {
                start = middle + 1;
            } else {
                end = middle;
            }
        }
        if start < nums.len() && start == nums[start] as usize {
            return -1;
        }
        start as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::special_array(vec![3, 5]), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::special_array(vec![0, 0]), -1);
}

#[test]
fn test3() {
    assert_eq!(Solution::special_array(vec![0, 4, 3, 0, 4]), 3);
}
