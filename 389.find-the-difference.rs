/*
 * @lc app=leetcode id=389 lang=rust
 *
 * [389] Find the Difference
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
    pub fn find_the_difference(s: String, t: String) -> char {

        s.as_bytes()
            .iter()
            .chain(t.as_bytes())
            .fold(0, |acc, &c| acc ^ c) as char
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_the_difference("abcd".to_string(), "abcde".to_string()),
        'e'
    );
    assert_eq!(
        Solution::find_the_difference("".to_string(), "y".to_string()),
        'y'
    );
    assert_eq!(
        Solution::find_the_difference("a".to_string(), "aa".to_string()),
        'a'
    );
    assert_eq!(
        Solution::find_the_difference("ae".to_string(), "aea".to_string()),
        'a'
    );
    assert_eq!(
        Solution::find_the_difference("ae".to_string(), "eaa".to_string()),
        'a'
    );
}
