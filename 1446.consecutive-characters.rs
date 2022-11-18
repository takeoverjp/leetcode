/*
 * @lc app=leetcode id=1446 lang=rust
 *
 * [1446] Consecutive Characters
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
    pub fn max_power(s: String) -> i32 {
        let mut ans = 0;
        let s = s.chars().collect::<Vec<char>>();
        for i in 0..s.len() {
            let mut j = i + 1;
            while j < s.len() && s[j] == s[j - 1] {
                j += 1;
            }
            ans = ans.max(j - i);
        }
        ans as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::max_power("leetcode".to_string()), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::max_power("abbcccddddeeeeedcba".to_string()), 5);
}
