/*
 * @lc app=leetcode id=257 lang=rust
 *
 * [257] Binary Tree Paths
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
    pub fn binary_tree_paths(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<String> {
        let mut ret = vec![];
        let mut stack = vec![(root, vec![])];

        while let Some((node, mut path)) = stack.pop() {
            if let Some(node) = node {
                let node = node.borrow();
                path.push(node.val.to_string());

                if node.left.is_none() && node.right.is_none() {
                    ret.push(path.join("->"));
                } else {
                    stack.push((node.right.clone(), path.clone()));
                    stack.push((node.left.clone(), path));
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
    let mut left = TreeNode::new(2);
    left.right = Some(Rc::new(RefCell::new(TreeNode::new(5))));
    root.left = Some(Rc::new(RefCell::new(left)));
    let mut right = TreeNode::new(3);
    root.right = Some(Rc::new(RefCell::new(right)));
    assert_eq!(
        Solution::binary_tree_paths(Some(Rc::new(RefCell::new(root)))),
        vec!["1->2->5", "1->3"]
    );
}

#[test]
fn test2() {
    let root = Some(Rc::new(RefCell::new(TreeNode::new(1))));
    assert_eq!(Solution::binary_tree_paths(root), vec!["1"]);
}
