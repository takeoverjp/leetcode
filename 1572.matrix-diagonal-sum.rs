/*
 * @lc app=leetcode id=1572 lang=rust
 *
 * [1572] Matrix Diagonal Sum
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
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
        let mut sum = 0;
        let len = mat.len();
        for (i, row) in mat.iter().enumerate() {
            sum += row[i] + row[len - 1 - i];
        }
        if len % 2 == 1 {
            sum -= mat[len / 2][len / 2];
        }
        sum
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::diagonal_sum(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]]),
        25
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::diagonal_sum(vec![
            vec![1, 1, 1, 1],
            vec![1, 1, 1, 1],
            vec![1, 1, 1, 1],
            vec![1, 1, 1, 1]
        ]),
        8
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::diagonal_sum(vec![vec![5]]), 5);
}
