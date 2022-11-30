/*
 * @lc app=leetcode id=1507 lang=rust
 *
 * [1507] Reformat Date
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
    pub fn reformat_date(date: String) -> String {
        let date = date.chars().collect::<Vec<char>>();
        if date.len() == 13 {
            date[9..13].iter().collect::<String>()
        } else {
            date[8..12].iter().collect::<String>()
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reformat_date("20th Oct 2052".to_string()),
        "2052-10-20".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reformat_date("6th Jun 1933".to_string()),
        "1933-06-06".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::reformat_date("26th May 1960".to_string()),
        "1960-05-26".to_string()
    );
}
