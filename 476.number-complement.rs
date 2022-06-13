/*
 * @lc app=leetcode id=476 lang=rust
 *
 * [476] Number Complement
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
    pub fn find_complement(num: i32) -> i32 {
        let mut sum = 1_u32;
        while sum <= num as u32 {
            sum <<= 1;
        }
        (sum - num as u32 - 1) as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_complement(15), 0);
    assert_eq!(Solution::find_complement(8), 7);
    assert_eq!(Solution::find_complement(5), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_complement(1), 0);
}
