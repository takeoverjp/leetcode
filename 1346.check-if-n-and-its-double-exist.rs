/*
 * @lc app=leetcode id=1346 lang=rust
 *
 * [1346] Check If N and Its Double Exist
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
    pub fn check_if_exist(arr: Vec<i32>) -> bool {
        for (idx, n) in arr.iter().enumerate() {
            for m in arr.iter().skip(idx + 1) {
                if *n == (2 * m) || *m == (2 * n) {
                    return true;
                }
            }
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::check_if_exist(vec![10, 2, 5, 3]));
}

#[test]
fn test2() {
    assert!(Solution::check_if_exist(vec![7, 1, 14, 11]));
}

#[test]
fn test3() {
    assert!(!Solution::check_if_exist(vec![3, 1, 7, 11]));
}
