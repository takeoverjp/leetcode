/*
 * @lc app=leetcode id=520 lang=rust
 *
 * [520] Detect Capital
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
    pub fn detect_capital_use(word: String) -> bool {
        let len = word.len();
        let chars = word.chars().collect::<Vec<char>>();
        if chars[0].is_ascii_lowercase() {
            for c in chars.iter().skip(1) {
                if c.is_ascii_uppercase() {
                    return false;
                }
            }
        } else {
            if len <= 1 {
                return true;
            }
            if chars[1].is_ascii_lowercase() {
                for c in chars.iter().skip(1) {
                    if c.is_ascii_uppercase() {
                        return false;
                    }
                }
            } else {
                for c in chars.iter().skip(1) {
                    if c.is_ascii_lowercase() {
                        return false;
                    }
                }
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::detect_capital_use("USA".to_string()));
}

#[test]
fn test2() {
    assert!(!Solution::detect_capital_use("FlaG".to_string()));
}
