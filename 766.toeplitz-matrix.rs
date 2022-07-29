/*
 * @lc app=leetcode id=766 lang=rust
 *
 * [766] Toeplitz Matrix
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
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let h = matrix.len();
        if h <= 1 {
            return true;
        }
        let w = matrix[0].len();
        if w <= 1 {
            return true;
        }
        for diff in (-(h as i32) + 1)..=(w as i32 - 1) {
            let mut val = -1;
            for x in 0..w {
                let y = x as i32 - diff;
                if y < 0 || y >= h as i32 {
                    continue;
                }
                if val < 0 {
                    val = matrix[y as usize][x];
                } else if val != matrix[y as usize][x] {
                    return false;
                }
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_toeplitz_matrix(vec![
        vec![1, 2, 3, 4],
        vec![5, 1, 2, 3],
        vec![9, 5, 1, 2]
    ]));
}

#[test]
fn test2() {
    assert!(!Solution::is_toeplitz_matrix(vec![vec![1, 2,], vec![2, 2]]));
}
