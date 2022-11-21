/*
 * @lc app=leetcode id=1460 lang=rust
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
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
    pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
        let mut tmap = std::collections::HashMap::<i32, usize>::new();
        let mut amap = std::collections::HashMap::<i32, usize>::new();
        for n in target {
            *tmap.entry(n).or_insert(0) += 1;
        }
        for n in arr {
            *amap.entry(n).or_insert(0) += 1;
        }
        tmap == amap
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::can_be_equal(vec![1, 2, 3, 4], vec![2, 4, 1, 3]));
}

#[test]
fn test2() {
    assert!(Solution::can_be_equal(vec![7], vec![7]));
}

#[test]
fn test3() {
    assert!(!Solution::can_be_equal(vec![3, 7, 9], vec![3, 7, 11]));
}
