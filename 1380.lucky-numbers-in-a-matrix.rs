/*
 * @lc app=leetcode id=1380 lang=rust
 *
 * [1380] Lucky Numbers in a Matrix
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
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let rows = matrix.len();
        let cols = matrix[0].len();
        let mut row_min = vec![i32::MAX; rows];
        let mut col_max = vec![i32::MIN; cols];

        for (i, row) in row_min.iter_mut().enumerate() {
            for (j, col) in col_max.iter_mut().enumerate() {
                let val = matrix[i][j];
                *row = (*row).min(val);
                *col = (*col).max(val);
            }
        }

        let mut ret = vec![];
        for (i, row) in row_min.iter().enumerate() {
            for (j, col) in col_max.iter().enumerate() {
                let val = matrix[i][j];
                if *row == val && *col == val {
                    ret.push(val);
                }
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::lucky_numbers(vec![vec![3, 7, 8], vec![9, 11, 13], vec![15, 16, 17]]),
        vec![15]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::lucky_numbers(vec![
            vec![1, 10, 4, 2],
            vec![9, 3, 8, 7],
            vec![15, 16, 17, 12]
        ]),
        vec![12]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::lucky_numbers(vec![vec![7, 8], vec![1, 2]]),
        vec![7]
    );
}
