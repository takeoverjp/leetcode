/*
 * @lc app=leetcode id=521 lang=rust
 *
 * [521] Longest Uncommon Subsequence I
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
    pub fn find_lu_slength(a: String, b: String) -> i32 {
        let alen = a.len() as i32;
        let blen = b.len() as i32;
        if alen != blen {
            return std::cmp::max(alen, blen);
        }
        if a != b {
            alen
        } else {
            -1
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_lu_slength("aba".to_string(), "cdc".to_string()),
        3
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_lu_slength("aaa".to_string(), "bbb".to_string()),
        3
    );
    assert_eq!(
        Solution::find_lu_slength("aaa".to_string(), "aaa".to_string()),
        -1
    );
}
