/*
 * @lc app=leetcode id=1021 lang=rust
 *
 * [1021] Remove Outermost Parentheses
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
    pub fn remove_outer_parentheses(s: String) -> String {
        let mut ret = String::new();
        let mut opened = 0;
        for c in s.chars() {
            if c == '(' {
                if opened > 0 {
                    ret.push(c);
                }
                opened += 1;
            } else {
                if opened > 1 {
                    ret.push(c);
                }
                opened -= 1;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::remove_outer_parentheses("(()())(())".to_string()),
        "()()()".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::remove_outer_parentheses("(()())(())(()(()))".to_string()),
        "()()()()(())".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::remove_outer_parentheses("()()".to_string()),
        "".to_string()
    );
}
