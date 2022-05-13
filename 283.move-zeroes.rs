/*
 * @lc app=leetcode id=283 lang=rust
 *
 * [283] Move Zeroes
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
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut zeroes = Vec::new();
        nums.retain(|x| {
            if *x != 0 {
                true
            } else {
                zeroes.push(0);
                false
            }
        });
        nums.append(&mut zeroes)
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut v = vec![0, 1, 0, 3, 12];
    Solution::move_zeroes(&mut v);
    assert_eq!(v, vec![1, 3, 12, 0, 0]);
}

#[test]
fn test2() {
    let mut v = vec![0];
    Solution::move_zeroes(&mut v);
    assert_eq!(v, vec![0]);
}
