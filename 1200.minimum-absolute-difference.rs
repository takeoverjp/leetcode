/*
 * @lc app=leetcode id=1200 lang=rust
 *
 * [1200] Minimum Absolute Difference
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
    pub fn minimum_abs_difference(mut arr: Vec<i32>) -> Vec<Vec<i32>> {
        arr.sort_unstable();
        let mut ret = Vec::<Vec<i32>>::new();
        let mut min_diff = i32::MAX;
        for i in 0..(arr.len() - 1) {
            min_diff = min_diff.min(arr[i + 1] - arr[i]);
        }
        for i in 0..(arr.len() - 1) {
            if arr[i + 1] - arr[i] == min_diff {
                ret.push(vec![arr[i], arr[i + 1]]);
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::minimum_abs_difference(vec![4, 2, 1, 3]),
        vec![vec![1, 2], vec![2, 3], vec![3, 4]]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::minimum_abs_difference(vec![1, 3, 6, 10, 15]),
        vec![vec![1, 3]]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::minimum_abs_difference(vec![3, 8, -10, 23, 19, -4, -14, 27]),
        vec![vec![-14, -10], vec![19, 23], vec![23, 27]]
    );
}
