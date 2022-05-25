/*
 * @lc app=leetcode id=374 lang=rust
 *
 * [374] Guess Number Higher or Lower
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
fn guess(n: i32) -> i32 {
    if n > 6 {
        -1
    } else if n < 6 {
        1
    } else {
        0
    }
}

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guessNumber(n: i32) -> i32 {
        let mut first = 1;
        let mut end = n;
        loop {
            let candidate = (((first as i64) + (end as i64)) / 2) as i32;
            let ret = guess(candidate);
            if ret == 0 {
                return candidate;
            } else if ret < 0 {
                end = candidate - 1;
            } else {
                first = candidate + 1;
            }
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    unsafe {
        assert_eq!(Solution::guessNumber(10), 6);
    }
}

#[test]
fn test2() {
    unsafe {
        assert_eq!(Solution::guessNumber(1), 1);
    }
}

#[test]
fn test3() {
    unsafe {
        assert_eq!(Solution::guessNumber(2), 1);
    }
}
