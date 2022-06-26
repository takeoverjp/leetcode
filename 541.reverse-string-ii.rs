/*
 * @lc app=leetcode id=541 lang=rust
 *
 * [541] Reverse String II
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
    pub fn reverse_str(s: String, k: i32) -> String {
        let len = s.len() as i32;
        let mut start = 0;
        let mut ret = s.chars().collect::<Vec<char>>();
        while start < len {
            let end = std::cmp::min(start + k, len) - 1;
            Solution::reverse_str_in(&mut ret, start, end);
            start += 2 * k;
        }
        ret.iter().collect()
    }

    fn reverse_str_in(s: &mut [char], start: i32, end: i32) {
        for i in 0..=((end - start - 1) / 2) {
            s.swap((end - i) as usize, (start + i) as usize);
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reverse_str("abcdefg".to_string(), 2),
        "bacdfeg".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reverse_str("abcd".to_string(), 2),
        "bacd".to_string()
    );
}
