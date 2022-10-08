/*
 * @lc app=leetcode id=1260 lang=rust
 *
 * [1260] Shift 2D Grid
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
    pub fn shift_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let n = grid.len();
        let m = grid[0].len();
        let k = k as usize;
        let mut ans = vec![vec![0; m]; n];
        for (i, row) in grid.iter().enumerate() {
            for (j, cell) in row.iter().enumerate() {
                let new_j = (j + k) % m;
                let new_i = (i + (j + k) / m) % n;
                ans[new_i][new_j] = *cell;
            }
        }
        ans
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::shift_grid(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]], 1),
        vec![vec![9, 1, 2], vec![3, 4, 5], vec![6, 7, 8]]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::shift_grid(
            vec![
                vec![3, 8, 1, 9],
                vec![19, 7, 2, 5],
                vec![4, 6, 11, 10],
                vec![12, 0, 21, 13]
            ],
            4
        ),
        vec![
            vec![12, 0, 21, 13],
            vec![3, 8, 1, 9],
            vec![19, 7, 2, 5],
            vec![4, 6, 11, 10]
        ]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::shift_grid(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]], 9),
        vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]
    );
}
