/*
 * @lc app=leetcode id=1566 lang=rust
 *
 * [1566] Detect Pattern of Length M Repeated K or More Times
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
    pub fn contains_pattern(arr: Vec<i32>, m: i32, k: i32) -> bool {
        let k = k as usize;
        let m = m as usize;
        if m * k > arr.len() {
            return false;
        }
        for i in 0..(arr.len() - m * k + 1) {
            let piece = &arr[i..(i + m)];
            if piece.repeat(k) == arr[i..(i + m * k)] {
                return true;
            }
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::contains_pattern(vec![1, 2, 4, 4, 4, 4], 1, 3));
}

#[test]
fn test2() {
    assert!(Solution::contains_pattern(
        vec![1, 2, 1, 2, 1, 1, 1, 3],
        2,
        2
    ));
}

#[test]
fn test3() {
    assert!(!Solution::contains_pattern(vec![1, 2, 1, 2, 1, 3], 2, 3));
}

#[test]
fn test4() {
    assert!(!Solution::contains_pattern(vec![2, 2, 2, 2], 2, 3));
}

#[test]
fn test5() {
    assert!(!Solution::contains_pattern(vec![1, 2], 1, 2));
}
