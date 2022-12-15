/*
 * @lc app=leetcode id=1582 lang=rust
 *
 * [1582] Special Positions in a Binary Matrix
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
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let mut res = 0;
        let n = mat.len();
        let m = mat[0].len();
        let mut row = vec![0; n];
        let mut col = vec![0; m];
        for (i, r) in mat.iter().enumerate() {
            for (j, elem) in r.iter().enumerate() {
                if *elem == 1 {
                    row[i] += 1;
                    col[j] += 1;
                }
            }
        }
        for (i, r) in mat.iter().enumerate() {
            for (j, elem) in r.iter().enumerate() {
                if *elem == 1 && row[i] == 1 && col[j] == 1 {
                    res += 1;
                }
            }
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::num_special(vec![vec![1, 0, 0], vec![0, 0, 1], vec![1, 0, 0]]),
        1
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::num_special(vec![vec![1, 0, 0], vec![0, 1, 0], vec![0, 0, 1]]),
        3
    );
}
