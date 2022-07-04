/*
 * @lc app=leetcode id=605 lang=rust
 *
 * [605] Can Place Flowers
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
    pub fn can_place_flowers(flowerbed: Vec<i32>, n: i32) -> bool {
        if n == 0 {
            return true;
        }
        let mut planted = 0;
        let mut is_adjacent = false;
        let len = flowerbed.len();
        for i in 0..len {
            let is_flower = flowerbed[i];
            if is_flower > 0 {
                is_adjacent = true;
                continue;
            }
            if i < len - 1 && flowerbed[i + 1] > 0 {
                is_adjacent = true;
            }
            if is_flower == 0 && !is_adjacent {
                planted += 1;
                if planted >= n {
                    return true;
                }
                is_adjacent = true;
                continue;
            }
            is_adjacent = false;
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::can_place_flowers(vec![1, 0, 0, 0, 1], 1));
}

#[test]
fn test2() {
    assert!(!Solution::can_place_flowers(vec![1, 0, 0, 0, 1], 2));
}
