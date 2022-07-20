/*
 * @lc app=leetcode id=709 lang=rust
 *
 * [709] To Lower Case
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
    pub fn to_lower_case(s: String) -> String {
        s.to_lowercase()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::to_lower_case("Hello".to_string()),
        "hello".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::to_lower_case("here".to_string()),
        "here".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::to_lower_case("LOVELY".to_string()),
        "lovely".to_string()
    );
}
