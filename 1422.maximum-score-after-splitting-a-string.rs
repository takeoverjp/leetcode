/*
 * @lc app=leetcode id=1422 lang=rust
 *
 * [1422] Maximum Score After Splitting a String
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
    pub fn max_score(s: String) -> i32 {
        let mut right_ones = 0;
        let mut left_zeros = 0;
        for c in s.chars() {
            if c == '1' {
                right_ones += 1;
            }
        }
        let mut score = 0;
        for c in s.chars().take(s.len() - 1) {
            if c == '0' {
                left_zeros += 1;
            } else {
                right_ones -= 1;
            }
            score = score.max(left_zeros + right_ones);
        }
        score
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::max_score("011101".to_string()), 5);
}

#[test]
fn test2() {
    assert_eq!(Solution::max_score("00111".to_string()), 5);
}

#[test]
fn test3() {
    assert_eq!(Solution::max_score("1111".to_string()), 3);
}
