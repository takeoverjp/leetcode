/*
 * @lc app=leetcode id=1518 lang=rust
 *
 * [1518] Water Bottles
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
    pub fn num_water_bottles(mut num_bottles: i32, num_exchange: i32) -> i32 {
        let mut res = num_bottles;
        while num_bottles >= num_exchange {
            let remaining_bottles = num_bottles % num_exchange;
            num_bottles /= num_exchange;
            res += num_bottles;
            num_bottles += remaining_bottles;
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::num_water_bottles(9, 3), 13);
}

#[test]
fn test2() {
    assert_eq!(Solution::num_water_bottles(15, 4), 19);
}
