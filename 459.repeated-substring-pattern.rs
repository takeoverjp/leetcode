/*
 * @lc app=leetcode id=459 lang=rust
 *
 * [459] Repeated Substring Pattern
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
    pub fn repeated_substring_pattern(s: String) -> bool {
        if s.len() < 2 {
            return false;
        }
        let mut s1 = s.clone();
        s1.push_str(&s);
        let s2 = &s1[1..=(2 * s.len() - 2)];
        s2.contains(&s)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::repeated_substring_pattern("abab".to_string()));
}

#[test]
fn test2() {
    assert!(!Solution::repeated_substring_pattern("aba".to_string()));
}

#[test]
fn test3() {
    assert!(Solution::repeated_substring_pattern(
        "abcabcabcabc".to_string()
    ));
}

#[test]
fn test4() {
    assert!(Solution::repeated_substring_pattern("bb".to_string()));
}
