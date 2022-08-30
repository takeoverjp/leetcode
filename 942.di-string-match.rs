/*
 * @lc app=leetcode id=942 lang=rust
 *
 * [942] DI String Match
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
    pub fn di_string_match(s: String) -> Vec<i32> {
        let mut ret = Vec::<i32>::new();
        let mut start = 0;
        let mut end = s.len() as i32;
        for c in s.chars() {
            if c == 'D' {
                ret.push(end);
                end -= 1;
            } else {
                ret.push(start);
                start += 1;
            }
        }
        ret.push(end);
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::di_string_match("IDID".to_string()),
        vec![0, 4, 1, 3, 2]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::di_string_match("III".to_string()),
        vec![0, 1, 2, 3]
    );
    assert_eq!(
        Solution::di_string_match("DDI".to_string()),
        vec![3, 2, 0, 1]
    );
}
