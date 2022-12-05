/*
 * @lc app=leetcode id=1528 lang=rust
 *
 * [1528] Shuffle String
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
    pub fn restore_string(s: String, indices: Vec<i32>) -> String {
        let s = s.chars().collect::<Vec<char>>();
        let mut res = s.clone();
        for i in 0..indices.len() {
            res[indices[i] as usize] = s[i];
        }
        res.iter().collect::<String>()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::restore_string("codeleet".to_string(), vec![4, 5, 6, 7, 0, 2, 1, 3]),
        "leetcode".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::restore_string("abc".to_string(), vec![0, 1, 2]),
        "abc".to_string()
    );
}
