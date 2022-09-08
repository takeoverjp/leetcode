/*
 * @lc app=leetcode id=1013 lang=rust
 *
 * [1013] Partition Array Into Three Parts With Equal Sum
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
    pub fn can_three_parts_equal_sum(arr: Vec<i32>) -> bool {
        let sum: i32 = arr.iter().sum();
        if sum % 3 != 0 {
            return false;
        }
        let (mut part, mut cnt) = (0, 0);
        let average = sum / 3;
        for (index, num) in arr.iter().enumerate() {
            part += num;
            if part == average {
                if cnt >= 1 && index < arr.len() - 1 {
                    return true;
                }
                cnt += 1;
                part = 0;
            }
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::can_three_parts_equal_sum(vec![
        0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1
    ]));
}

#[test]
fn test2() {
    assert!(!Solution::can_three_parts_equal_sum(vec![
        0, 2, 1, -6, 6, 7, 9, -1, 2, 0, 1
    ]));
}

#[test]
fn test3() {
    assert!(Solution::can_three_parts_equal_sum(vec![
        3, 3, 6, 5, -2, 2, 5, 1, -9, 4
    ]));
}

#[test]
fn test4() {
    assert!(Solution::can_three_parts_equal_sum(vec![
        18, 12, -18, 18, -19, -1, 10, 10
    ]));
}

#[test]
fn test5() {
    assert!(!Solution::can_three_parts_equal_sum(vec![1, -1, 1, -1]));
}
