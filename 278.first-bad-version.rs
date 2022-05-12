/*
 * @lc app=leetcode id=278 lang=rust
 *
 * [278] First Bad Version
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
// The API isBadVersion is defined for you.
// isBadVersion(version:i32)-> bool;
// to call it use self.isBadVersion(version)

impl Solution {
    pub fn first_bad_version(&self, n: i32) -> i32 {
        self.rec(1, n)
    }

    fn rec(&self, start: i32, end: i32) -> i32{
        let mut mid = (start as i64 + end as i64) / 2;
        if mid == start as i64 {
            if self.isBadVersion(mid as i32) {
                return start;
            } else {
                return end;
            }
        }
        if self.isBadVersion(mid as i32) {
            return self.rec(start, mid as i32);
        } else {
            return self.rec(mid as i32, end);
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::first_bad_version(5, 4), 4);
}

#[test]
fn test2() {
    assert_eq!(Solution::first_bad_version(1, 1), 1);
}
