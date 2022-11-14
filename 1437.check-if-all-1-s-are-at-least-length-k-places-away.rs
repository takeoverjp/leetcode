/*
 * @lc app=leetcode id=1437 lang=rust
 *
 * [1437] Check If All 1's Are at Least Length K Places Away
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
    pub fn k_length_apart(nums: Vec<i32>, k: i32) -> bool {
        let mut prev_one = -k - 1;
        for (i, num) in nums.iter().enumerate() {
            if *num > 0 {
                if i as i32 - prev_one <= k {
                    return false;
                }
                prev_one = i as i32;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::k_length_apart(vec![1, 0, 0, 0, 1, 0, 0, 1], 2));
}

#[test]
fn test2() {
    assert!(!Solution::k_length_apart(vec![1, 0, 0, 1, 0, 1], 2));
}
