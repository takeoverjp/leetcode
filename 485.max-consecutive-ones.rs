/*
 * @lc app=leetcode id=485 lang=rust
 *
 * [485] Max Consecutive Ones
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
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut ret = 0;
        let mut current = 0;
        for num in nums {
            if num != 0 {
                current += 1;
            } else {
                current = 0;
            }
            if current > ret {
                ret = current;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_max_consecutive_ones(vec![1, 1, 0, 1, 1, 1]),
        3
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_max_consecutive_ones(vec![1, 0, 1, 1, 0, 1]),
        2
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::find_max_consecutive_ones(vec![0]), 0);
}

#[test]
fn test4() {
    assert_eq!(Solution::find_max_consecutive_ones(vec![1]), 1);
}
