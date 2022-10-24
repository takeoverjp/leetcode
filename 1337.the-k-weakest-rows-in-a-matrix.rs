/*
 * @lc app=leetcode id=1337 lang=rust
 *
 * [1337] The K Weakest Rows in a Matrix
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
    pub fn k_weakest_rows(mut mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let n = mat[0].len();
        for (i, mat) in mat.iter_mut().enumerate() {
            mat.push(i as i32);
        }
        mat.sort();
        let mut ans = Vec::new();
        ans.reserve(k as usize);
        for i in 0..k {
            ans.push(mat[i as usize][n]);
        }
        ans
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::k_weakest_rows(
            vec![
                vec![1, 1, 0, 0, 0],
                vec![1, 1, 1, 1, 0],
                vec![1, 0, 0, 0, 0],
                vec![1, 1, 0, 0, 0],
                vec![1, 1, 1, 1, 1]
            ],
            3
        ),
        vec![2, 0, 3]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::k_weakest_rows(
            vec![
                vec![1, 0, 0, 0],
                vec![1, 1, 1, 1],
                vec![1, 0, 0, 0],
                vec![1, 0, 0, 0]
            ],
            2
        ),
        vec![0, 2]
    );
}
