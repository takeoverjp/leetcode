/*
 * @lc app=leetcode id=1614 lang=rust
 *
 * [1614] Maximum Nesting Depth of the Parentheses
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
    pub fn max_depth(s: String) -> i32 {
        let mut max_depth = 0;
        let mut balance = 0;
        for c in s.chars() {
            match c {
                '(' => balance += 1,
                ')' => balance -= 1,
                _ => continue,
            }
            max_depth = max_depth.max(balance);
        }
        max_depth
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::max_depth("(1+(2*3)+((8)/4))+1".to_string()), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::max_depth("(1)+((2))+(((3)))".to_string()), 3);
}
