/*
 * @lc app=leetcode id=387 lang=rust
 *
 * [387] First Unique Character in a String
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
    pub fn first_uniq_char(s: String) -> i32 {
        let mut m: std::collections::HashMap<char, i32> = std::collections::HashMap::new();

        for c in s.chars() {
            *m.entry(c).or_insert(0) += 1;
        }
        for (idx, c) in s.chars().enumerate() {
            if *m.get(&c).unwrap() == 1 {
                return idx as i32;
            }
        }
        -1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::first_uniq_char("leetcode".to_string()), 0);
}

#[test]
fn test2() {
    assert_eq!(Solution::first_uniq_char("loveleetcode".to_string()), 2);
}

#[test]
fn test3() {
    assert_eq!(Solution::first_uniq_char("aabb".to_string()), -1);
}
