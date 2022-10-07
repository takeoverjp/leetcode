/*
 * @lc app=leetcode id=1252 lang=rust
 *
 * [1252] Cells with Odd Values in a Matrix
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
    pub fn odd_cells(m: i32, n: i32, indices: Vec<Vec<i32>>) -> i32 {
        let mut rows = Vec::<bool>::new();
        rows.resize(n as usize, false);
        let mut cols = Vec::<bool>::new();
        cols.resize(m as usize, false);
        for idx in &indices {
            rows[idx[0] as usize] = !rows[idx[0] as usize];
            cols[idx[1] as usize] = !cols[idx[1] as usize];
        }
        let mut ret = 0;
        for i in 0..n {
            for j in 0..m {
                ret += if rows[i as usize] ^ cols[j as usize] {
                    1
                } else {
                    0
                };
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::odd_cells(2, 3, vec![vec![0, 1], vec![1, 1]]), 6);
}

#[test]
fn test2() {
    assert_eq!(Solution::odd_cells(2, 2, vec![vec![1, 1], vec![0, 0]]), 0);
}
