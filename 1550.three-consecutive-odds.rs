/*
 * @lc app=leetcode id=1550 lang=rust
 *
 * [1550] Three Consecutive Odds
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
    pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
        let mut odds = 0;
        let mut i = 0;
        while i < arr.len() && odds < 3 {
            odds = if arr[i] % 2 == 1 { odds + 1 } else { 0 };
            i += 1;
        }
        odds == 3
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(!Solution::three_consecutive_odds(vec![2, 6, 4, 1]));
}

#[test]
fn test2() {
    assert!(Solution::three_consecutive_odds(vec![
        1, 2, 34, 3, 4, 5, 7, 23, 12
    ]));
}
