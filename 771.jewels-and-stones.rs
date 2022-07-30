/*
 * @lc app=leetcode id=771 lang=rust
 *
 * [771] Jewels and Stones
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
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut count = 0;
        for jewel in jewels.chars() {
            for stone in stones.chars() {
                if stone == jewel {
                    count += 1;
                }
            }
        }
        count
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::num_jewels_in_stones("aA".to_string(), "aAAbbbb".to_string()),
        3
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::num_jewels_in_stones("z".to_string(), "XX".to_string()),
        0
    );
}
