/*
 * @lc app=leetcode id=144 lang=rust
 *
 * [144] Binary Tree Preorder Traversal
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
    pub fn preorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut node_stack = vec![];
        let mut ret = vec![];
        let mut curr = root;
        while (!curr.is_none()) || (node_stack.len() > 0) {
            match curr {
                Some(ref curr2) => {
                    ret.push(curr2.borrow().val);
                    node_stack.push(curr2.clone());
                    curr = curr2.clone().borrow().left.clone();
                }
                None => {
                    let node = node_stack.pop();
                    curr = node.unwrap().borrow().right.clone();
                }
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut root = TreeNode::new(1);
    let mut right = TreeNode::new(2);
    right.left = Some(Rc::new(RefCell::new(TreeNode::new(3))));
    root.right = Some(Rc::new(RefCell::new(right)));
    assert_eq!(
        Solution::preorder_traversal(Some(Rc::new(RefCell::new(root)))),
        vec![1, 2, 3]
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::preorder_traversal(None), vec![]);
}

#[test]
fn test3() {
    let mut root = TreeNode::new(1);
    assert_eq!(
        Solution::preorder_traversal(Some(Rc::new(RefCell::new(root)))),
        vec![1]
    );
}
