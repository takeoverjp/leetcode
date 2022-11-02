/*
 * @lc app=leetcode id=1374 lang=rust
 *
 * [1374] Generate a String With Characters That Have Odd Counts
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
    pub fn generate_the_string(n: i32) -> String {
        let n = n as usize;
        if n % 2 == 0 {
            vec!['a'; n - 1].iter().collect::<String>() + "b"
        } else {
            vec!['a'; n].iter().collect::<String>()
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::generate_the_string(4), "aaab".to_string());
}

#[test]
fn test2() {
    assert_eq!(Solution::generate_the_string(2), "ab".to_string());
}

#[test]
fn test3() {
    assert_eq!(Solution::generate_the_string(7), "aaaaaaa".to_string());
}
