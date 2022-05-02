/*
 * @lc app=leetcode id=234 lang=rust
 *
 * [234] Palindrome Linked List
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
// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn is_palindrome(head: Option<Box<ListNode>>) -> bool {
        let mut cnt = 0;
        let mut curr = &head;
        while let Some(ref node) = curr {
            cnt += 1;
            curr = &node.next;
        }
        let mut v = vec![];
        let last;
        let first;
        last = cnt / 2 - 1;
        if cnt % 2 == 0 {
            first = cnt / 2;
        } else {
            first = cnt / 2 + 1;
        }
        let mut curr = &head;
        let mut i = 0;
        while let Some(ref node) = curr {
            if i <= last {
                v.push(node.val)
            } else if i >= first && v.pop().unwrap() != node.val {
                return false;
            }
            curr = &node.next;
            i += 1;
        }
        true
    }
}
// @lc code=end

#[allow(unused_assignments)]
#[test]
fn test1() {
    assert!(Solution::is_palindrome(list_node![1, 2, 2, 1]));
}

#[allow(unused_assignments)]
#[test]
fn test2() {
    assert!(!Solution::is_palindrome(list_node![1, 2]));
}
