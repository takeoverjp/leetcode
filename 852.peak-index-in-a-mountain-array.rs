/*
 * @lc app=leetcode id=852 lang=rust
 *
 * [852] Peak Index in a Mountain Array
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
    pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
        let size = arr.len();
        let mut start = 0;
        let mut end = size - 1;
        let mut mid = (start + end) / 2;
        loop {
            if (arr[mid - 1] < arr[mid]) && (arr[mid] > arr[mid + 1]) {
                return mid as i32;
            }
            if arr[mid - 1] < arr[mid] {
                start = end.min(mid + 1);
                mid = (size - 2).min((start + end) / 2);
                continue;
            }
            if arr[mid - 1] > arr[mid] {
                end = start.max(mid - 1);
                mid = 1.max((start + end) / 2);
                continue;
            }
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::peak_index_in_mountain_array(vec![0, 1, 0]), 1);
}

#[test]
fn test2() {
    assert_eq!(Solution::peak_index_in_mountain_array(vec![0, 2, 1, 0]), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::peak_index_in_mountain_array(vec![0, 10, 5, 2]), 1);
}
