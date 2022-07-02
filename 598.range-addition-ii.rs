/*
 * @lc app=leetcode id=598 lang=rust
 *
 * [598] Range Addition II
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
    pub fn max_count(m: i32, n: i32, ops: Vec<Vec<i32>>) -> i32 {
        let mut min_row = m;
        let mut min_col = n;
        for op in ops {
            min_row = min_row.min(op[0]);
            min_col = min_col.min(op[1]);
        }
        min_row * min_col
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::max_count(3, 3, vec![vec![2, 2], vec![3, 3]]), 4);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::max_count(
            3,
            3,
            vec![
                vec![2, 2],
                vec![3, 3],
                vec![3, 3],
                vec![3, 3],
                vec![2, 2],
                vec![3, 3],
                vec![3, 3],
                vec![3, 3],
                vec![2, 2],
                vec![3, 3],
                vec![3, 3],
                vec![3, 3]
            ]
        ),
        4
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::max_count(3, 3, vec![]), 9);
}
