/*
 * @lc app=leetcode id=1598 lang=rust
 *
 * [1598] Crawler Log Folder
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
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut depth = 0;
        for dir in logs {
            if dir == "../" && depth > 0 {
                depth -= 1;
            } else if dir != "./" && dir != "../" {
                depth += 1;
            }
        }
        depth
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::min_operations(vec![
            "d1/".to_string(),
            "d2/".to_string(),
            "../".to_string(),
            "d21/".to_string(),
            "./".to_string()
        ]),
        2
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::min_operations(vec![
            "d1/".to_string(),
            "d2/".to_string(),
            "./".to_string(),
            "d3/".to_string(),
            "../".to_string(),
            "d31/".to_string()
        ]),
        3
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::min_operations(vec![
            "d1/".to_string(),
            "../".to_string(),
            "../".to_string(),
            "../".to_string(),
        ]),
        0
    );
}
