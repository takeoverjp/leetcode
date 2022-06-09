/*
 * @lc app=leetcode id=455 lang=rust
 *
 * [455] Assign Cookies
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
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        g.sort_unstable();
        s.sort_unstable();
        let child_num = g.len();
        let cookie_num = s.len();
        let mut i = 0;
        let mut j = 0;
        while i < child_num && j < cookie_num {
            if g[i] <= s[j] {
                i += 1;
            }
            j += 1;
        }
        i as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_content_children(vec![1, 2, 3], vec![1, 1]),
        1
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_content_children(vec![1, 2], vec![1, 2, 3]),
        2
    );
}
