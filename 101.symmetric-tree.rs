/*
 * @lc app=leetcode id=101 lang=rust
 *
 * [101] Symmetric Tree
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
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
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
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
//
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn is_symmetric(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
        match root {
            Some(root) => {
                let root = root.borrow();
                Solution::is_symmetric_recursive(&root.left, &root.right)
            }
            _ => true,
        }
    }
    fn is_symmetric_recursive(
        left: &Option<Rc<RefCell<TreeNode>>>,
        right: &Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        match (left, right) {
            (Some(left), Some(right)) => {
                let (left, right) = (left.borrow(), right.borrow());
                if left.val != right.val {
                    return false;
                }
                Solution::is_symmetric_recursive(&left.left, &right.right)
                    && Solution::is_symmetric_recursive(&left.right, &right.left)
            }
            (None, None) => true,
            _ => false,
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut root = TreeNode::new(1);
    let mut left = TreeNode::new(2);
    left.left = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    left.right = Some(Rc::new(RefCell::new(TreeNode::new(4))));
    let mut right = TreeNode::new(2);
    right.left = Some(Rc::new(RefCell::new(TreeNode::new(4))));
    right.right = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    root.left = Some(Rc::new(RefCell::new(left)));
    root.right = Some(Rc::new(RefCell::new(right)));
    assert!(Solution::is_symmetric(Some(Rc::new(RefCell::new(root)))));
}

#[test]
fn test2() {
    let mut root = TreeNode::new(1);
    let mut left = TreeNode::new(2);
    left.right = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    let mut right = TreeNode::new(2);
    right.right = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    root.left = Some(Rc::new(RefCell::new(left)));
    root.right = Some(Rc::new(RefCell::new(right)));
    assert!(!Solution::is_symmetric(Some(Rc::new(RefCell::new(root)))));
}
