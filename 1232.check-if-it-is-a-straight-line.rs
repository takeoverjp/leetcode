/*
 * @lc app=leetcode id=1232 lang=rust
 *
 * [1232] Check If It Is a Straight Line
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
    pub fn check_straight_line(coordinates: Vec<Vec<i32>>) -> bool {
        let dy = coordinates[1][1] - coordinates[0][1];
        let dx = coordinates[1][0] - coordinates[0][0];
        for i in 2..coordinates.len() {
            let p = &coordinates[i];
            if dx * (p[1] - coordinates[0][1]) != dy * (p[0] - coordinates[0][0]) {
                return false;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::check_straight_line(vec![
        vec![1, 2],
        vec![2, 3],
        vec![3, 4],
        vec![4, 5],
        vec![5, 6],
        vec![6, 7]
    ]));
}

#[test]
fn test2() {
    assert!(!Solution::check_straight_line(vec![
        vec![1, 1],
        vec![2, 2],
        vec![3, 4],
        vec![4, 5],
        vec![5, 6],
        vec![7, 7]
    ]));
}
