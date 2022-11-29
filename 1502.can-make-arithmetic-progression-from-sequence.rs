/*
 * @lc app=leetcode id=1502 lang=rust
 *
 * [1502] Can Make Arithmetic Progression From Sequence
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
    pub fn can_make_arithmetic_progression(arr: Vec<i32>) -> bool {
        let s = arr.iter().collect::<std::collections::HashSet<&i32>>();
        let mut max_element = i32::MIN;
        let mut min_element = i32::MAX;
        for e in &arr {
            max_element = max_element.max(*e);
            min_element = min_element.min(*e);
        }
        let diff = (max_element - min_element) / (arr.len() as i32 - 1);
        for i in 1..arr.len() {
            if !s.contains(&(min_element + i as i32 * diff)) {
                return false;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::can_make_arithmetic_progression(vec![3, 5, 1]));
}

#[test]
fn test2() {
    assert!(!Solution::can_make_arithmetic_progression(vec![1, 2, 4]));
}
