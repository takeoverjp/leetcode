/*
 * @lc app=leetcode id=235 lang=rust
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        root
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut root = TreeNode::new(6);
    let left = Some(Rc::new(RefCell::new(TreeNode {
        val: 2,
        left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 4,
            left: Some(Rc::new(RefCell::new(TreeNode::new(3)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(5)))),
        }))),
    })));
    root.left = left.clone();
    let right = Some(Rc::new(RefCell::new(TreeNode {
        val: 8,
        left: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
        right: Some(Rc::new(RefCell::new(TreeNode::new(9)))),
    })));
    root.right = right.clone();
    let root = Some(Rc::new(RefCell::new(root)));
    assert_eq!(
        Solution::lowest_common_ancestor(root.clone(), left, right),
        root
    );
}

#[test]
fn test2() {
    let mut root = TreeNode::new(6);
    let left = Some(Rc::new(RefCell::new(TreeNode {
        val: 2,
        left: Some(Rc::new(RefCell::new(TreeNode::new(0)))),
        right: Some(Rc::new(RefCell::new(TreeNode {
            val: 4,
            left: Some(Rc::new(RefCell::new(TreeNode::new(3)))),
            right: Some(Rc::new(RefCell::new(TreeNode::new(5)))),
        }))),
    })));
    root.left = left.clone();
    let right = Some(Rc::new(RefCell::new(TreeNode {
        val: 8,
        left: Some(Rc::new(RefCell::new(TreeNode::new(7)))),
        right: Some(Rc::new(RefCell::new(TreeNode::new(9)))),
    })));
    root.right = right.clone();
    let root = Some(Rc::new(RefCell::new(root)));
    assert_eq!(
        Solution::lowest_common_ancestor(root, left.clone(), right),
        left
    );
}

#[test]
fn test3() {
    let mut root = TreeNode::new(2);
    let left = Some(Rc::new(RefCell::new(TreeNode::new(1))));
    root.left = left.clone();
    let root = Some(Rc::new(RefCell::new(root)));
    assert_eq!(
        Solution::lowest_common_ancestor(root.clone(), root.clone(), left),
        root
    );
}
