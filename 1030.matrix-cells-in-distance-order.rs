/*
 * @lc app=leetcode id=1030 lang=rust
 *
 * [1030] Matrix Cells in Distance Order
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
    pub fn all_cells_dist_order(
        rows: i32,
        cols: i32,
        r_center: i32,
        c_center: i32,
    ) -> Vec<Vec<i32>> {
        let mut ret = Vec::<Vec<i32>>::new();
        for i in 0..rows {
            for j in 0..cols {
                ret.push(vec![i, j, (i - r_center).abs() + (j - c_center).abs()]);
            }
        }
        ret.sort_by(|a, b| a[2].cmp(&b[2]));
        for d in &mut ret {
            d.remove(d.len() - 1);
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::all_cells_dist_order(1, 2, 0, 0),
        vec![vec![0, 0], vec![0, 1]]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::all_cells_dist_order(2, 2, 0, 1),
        vec![vec![0, 1], vec![0, 0], vec![1, 1], vec![1, 0],]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::all_cells_dist_order(2, 3, 1, 2),
        vec![
            vec![1, 2],
            vec![0, 2],
            vec![1, 1],
            vec![0, 1],
            vec![1, 0],
            vec![0, 0]
        ]
    );
}
