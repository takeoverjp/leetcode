/*
 * @lc app=leetcode id=392 lang=rust
 *
 * [392] Is Subsequence
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
    pub fn is_subsequence(s: String, t: String) -> bool {
        let mut iterator = t.chars();
        for sc in s.chars() {
            match iterator.find(|&tc| sc == tc) {
                Some(_) => {}
                _ => {
                    return false;
                }
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_subsequence(
        "".to_string(),
        "abcde".to_string()
    ));
    assert!(!Solution::is_subsequence("abc".to_string(), "".to_string()));
    assert!(Solution::is_subsequence(
        "ace".to_string(),
        "abcde".to_string()
    ));
    assert!(!Solution::is_subsequence(
        "aec".to_string(),
        "abcde".to_string()
    ));
    assert!(Solution::is_subsequence(
        "abc".to_string(),
        "ahbgdc".to_string()
    ));
    assert!(!Solution::is_subsequence(
        "axc".to_string(),
        "ahbgdc".to_string()
    ));
    assert!(!Solution::is_subsequence(
        "aaaaaa".to_string(),
        "bbaaaa".to_string()
    ));
}
