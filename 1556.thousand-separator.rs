/*
 * @lc app=leetcode id=1556 lang=rust
 *
 * [1556] Thousand Separator
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
    pub fn thousand_separator(n: i32) -> String {
        let s = n.to_string().chars().collect::<Vec<char>>();
        let mut res = "".to_string();
        for i in 0..s.len() {
            if i > 0 && (s.len() - i) % 3 == 0 {
                res += ".";
            }
            res += &s[i].to_string();
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::thousand_separator(987), "987".to_string());
}

#[test]
fn test2() {
    assert_eq!(Solution::thousand_separator(1234), "1.234".to_string());
}
