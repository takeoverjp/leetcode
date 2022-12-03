/*
 * @lc app=leetcode id=1523 lang=rust
 *
 * [1523] Count Odd Numbers in an Interval Range
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
    pub fn count_odds(low: i32, high: i32) -> i32 {
        let mut res = (high - low) / 2;
        if low % 2 != 0 || high % 2 != 0 {
            res += 1;
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::count_odds(3, 7), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::count_odds(8, 10), 1);
}
