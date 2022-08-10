/*
 * @lc app=leetcode id=836 lang=rust
 *
 * [836] Rectangle Overlap
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
    pub fn is_rectangle_overlap(rec1: Vec<i32>, rec2: Vec<i32>) -> bool {
        let w1 = rec1[2] - rec1[0];
        let h1 = rec1[3] - rec1[1];
        let w2 = rec2[2] - rec2[0];
        let h2 = rec2[3] - rec2[1];
        if w1 == 0 || h1 == 0 || w2 == 0 || h2 == 0 {
            return false;
        }
        ((rec1[0] < rec2[0] && rec2[0] < rec1[2])
            || (rec2[0] < rec1[0] && rec1[0] < rec2[2])
            || (rec1[0] < rec2[2] && rec2[2] < rec1[2])
            || (rec2[0] < rec1[2] && rec1[2] < rec2[2]))
            && ((rec1[1] < rec2[1] && rec2[1] < rec1[3])
                || (rec2[1] < rec1[1] && rec1[1] < rec2[3])
                || (rec1[1] < rec2[3] && rec2[3] < rec1[3])
                || (rec2[1] < rec1[3] && rec1[3] < rec2[3]))
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_rectangle_overlap(
        vec![0, 0, 2, 2],
        vec![1, 1, 3, 3]
    ));
}

#[test]
fn test2() {
    assert!(!Solution::is_rectangle_overlap(
        vec![0, 0, 1, 1],
        vec![1, 0, 2, 1]
    ));
}

#[test]
fn test3() {
    assert!(!Solution::is_rectangle_overlap(
        vec![0, 0, 1, 1],
        vec![2, 2, 3, 3]
    ));
}
