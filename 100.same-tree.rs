/*
 * @lc app=leetcode id=100 lang=rust
 *
 * [100] Same Tree
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
    pub fn is_same_tree(
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> bool {
        if p.is_none() {
            if q.is_none() {
                return true;
            } else {
                return false;
            }
        } else if q.is_none() {
            return false;
        } else {
            if (*p.as_ref().unwrap()).borrow().val != (*q.as_ref().unwrap()).borrow().val {
                return false;
            }

            if !Solution::is_same_tree(
                (*p.as_ref().unwrap()).borrow().left.clone(),
                (*q.as_ref().unwrap()).borrow().left.clone(),
            ) {
                return false;
            }

            if !Solution::is_same_tree(
                (*p.as_ref().unwrap()).borrow().right.clone(),
                (*q.as_ref().unwrap()).borrow().right.clone(),
            ) {
                return false;
            }

            return true;
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut p = TreeNode::new(1);
    p.left = Some(Rc::new(RefCell::new(TreeNode::new(2))));
    p.right = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    let mut q = TreeNode::new(1);
    q.left = Some(Rc::new(RefCell::new(TreeNode::new(2))));
    q.right = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    assert!(Solution::is_same_tree(
        Some(Rc::new(RefCell::new(p))),
        Some(Rc::new(RefCell::new(q)))
    ));
}

#[test]
fn test2() {
    let mut p = TreeNode::new(1);
    p.left = Some(Rc::new(RefCell::new(TreeNode::new(2))));
    let mut q = TreeNode::new(1);
    q.right = Some(Rc::new(RefCell::new(TreeNode::new(2))));
    assert!(!Solution::is_same_tree(
        Some(Rc::new(RefCell::new(p))),
        Some(Rc::new(RefCell::new(q)))
    ));
}
