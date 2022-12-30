/*
 * @lc app=leetcode id=1662 lang=rust
 *
 * [1662] Check If Two String Arrays are Equivalent
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
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let mut word1_combined = String::new();
        for s in word1 {
            word1_combined += &s;
        }
        let mut word2_combined = String::new();
        for s in word2 {
            word2_combined += &s;
        }
        word1_combined == word2_combined
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::array_strings_are_equal(
        vec!["ab".to_string(), "c".to_string()],
        vec!["a".to_string(), "bc".to_string()]
    ));
}

#[test]
fn test2() {
    assert!(!Solution::array_strings_are_equal(
        vec!["a".to_string(), "cb".to_string()],
        vec!["ab".to_string(), "c".to_string()]
    ));
}

#[test]
fn test3() {
    assert!(Solution::array_strings_are_equal(
        vec!["abc".to_string(), "d".to_string(), "defg".to_string()],
        vec!["abcddefg".to_string()]
    ));
}
