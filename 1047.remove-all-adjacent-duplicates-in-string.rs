/*
 * @lc app=leetcode id=1047 lang=rust
 *
 * [1047] Remove All Adjacent Duplicates In String
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
    pub fn remove_duplicates(s: String) -> String {
        let mut a = Vec::<char>::new();
        for c in s.chars() {
            if !a.is_empty() && a[a.len() - 1] == c {
                a.remove(a.len() - 1);
            } else {
                a.push(c);
            }
        }
        a.iter().collect::<String>()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::remove_duplicates("abbaca".to_string()),
        "ca".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::remove_duplicates("azxxzy".to_string()),
        "ay".to_string()
    );
}
