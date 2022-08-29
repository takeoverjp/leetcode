/*
 * @lc app=leetcode id=941 lang=rust
 *
 * [941] Valid Mountain Array
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
    pub fn valid_mountain_array(arr: Vec<i32>) -> bool {
        let n = arr.len();
        let (mut i, mut j) = (0, n - 1);
        while i + 1 < n && arr[i] < arr[i + 1] {
            i += 1;
        }
        while j > 0 && arr[j - 1] > arr[j] {
            j -= 1;
        }
        i > 0 && i == j && j < n - 1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(!Solution::valid_mountain_array(vec![2, 1]));
}

#[test]
fn test2() {
    assert!(!Solution::valid_mountain_array(vec![3, 5, 5]));
}

#[test]
fn test3() {
    assert!(Solution::valid_mountain_array(vec![0, 3, 2, 1]));
}
