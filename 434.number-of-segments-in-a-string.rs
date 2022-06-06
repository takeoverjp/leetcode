/*
 * @lc app=leetcode id=434 lang=rust
 *
 * [434] Number of Segments in a String
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
    pub fn count_segments(s: String) -> i32 {
        let mut in_seg = false;
        let mut ret = 0;
        for c in s.chars() {
            if c == ' ' {
                if in_seg {
                    in_seg = false;
                }
            } else if !in_seg {
                ret += 1;
                in_seg = true;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::count_segments("Hello, my name is John".to_string()),
        5
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::count_segments("Hello".to_string()), 1);
}
