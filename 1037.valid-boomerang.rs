/*
 * @lc app=leetcode id=1037 lang=rust
 *
 * [1037] Valid Boomerang
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
    pub fn is_boomerang(p: Vec<Vec<i32>>) -> bool {
        p[0][0] * (p[1][1] - p[2][1])
            + p[1][0] * (p[2][1] - p[0][1])
            + p[2][0] * (p[0][1] - p[1][1])
            != 0
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_boomerang(vec![
        vec![1, 1],
        vec![2, 3],
        vec![3, 2]
    ]));
}

#[test]
fn test2() {
    assert!(!Solution::is_boomerang(vec![
        vec![1, 1],
        vec![2, 2],
        vec![3, 3]
    ]));
}
