/*
 * @lc app=leetcode id=883 lang=rust
 *
 * [883] Projection Area of 3D Shapes
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
    pub fn projection_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        let mut max_in_cols = vec![0; grid.len()];
        for row in &grid {
            let mut max_in_row = 0;
            for (col, &val) in row.iter().enumerate().filter(|(_, val)| **val > 0) {
                max_in_row = max_in_row.max(val);
                max_in_cols[col] = max_in_cols[col].max(val);
                res += 1;
            }
            res += max_in_row;
        }
        res + max_in_cols.iter().sum::<i32>()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::projection_area(vec![vec![1, 2], vec![3, 4]]), 17);
    assert_eq!(Solution::projection_area(vec![vec![2]]), 5);
    assert_eq!(Solution::projection_area(vec![vec![1, 0], vec![0, 2]]), 8);
}
