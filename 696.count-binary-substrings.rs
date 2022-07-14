/*
 * @lc app=leetcode id=696 lang=rust
 *
 * [696] Count Binary Substrings
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
    pub fn count_binary_substrings(s: String) -> i32 {
        let mut count = 0;
        let len = s.len();
        let s = s.chars().collect::<Vec<char>>();
        let mut current_run_length = 1;
        let mut previous_run_length = 0;
        for i in 1..len {
            if s[i] == s[i - 1] {
                current_run_length += 1;
            } else {
                previous_run_length = current_run_length;
                current_run_length = 1;
            }
            if previous_run_length >= current_run_length {
                count += 1;
            }
        }
        count
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::count_binary_substrings("00110011".to_string()), 6);
}

#[test]
fn test2() {
    assert_eq!(Solution::count_binary_substrings("10101".to_string()), 4);
}
