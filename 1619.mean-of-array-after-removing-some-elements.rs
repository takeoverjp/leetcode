/*
 * @lc app=leetcode id=1619 lang=rust
 *
 * [1619] Mean of Array After Removing Some Elements
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
    pub fn trim_mean(mut arr: Vec<i32>) -> f64 {
        let n = arr.len();
        let k = n / 20;
        arr.sort_unstable();
        let mut sum = 0;
        for a in arr.iter().take(n - k).skip(k) {
            sum += a;
        }
        sum as f64 / (n as f64 - 2.0 * k as f64)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::trim_mean(vec![
            1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3
        ]),
        2.00000
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::trim_mean(vec![
            6, 2, 7, 5, 1, 2, 0, 3, 10, 2, 5, 0, 5, 5, 0, 8, 7, 6, 8, 0
        ]),
        4.00000
    );
}

#[test]
fn test3() {
    assert_eq!(
        (Solution::trim_mean(vec![
            6, 0, 7, 0, 7, 5, 7, 8, 3, 4, 0, 7, 8, 1, 6, 8, 1, 1, 2, 4, 8, 1, 9, 5, 4, 3, 8, 5, 10,
            8, 6, 6, 1, 0, 6, 10, 8, 2, 3, 4
        ]) * 100000.0)
            .round() as i32,
        477778
    );
}
