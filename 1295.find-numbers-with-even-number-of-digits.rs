/*
 * @lc app=leetcode id=1295 lang=rust
 *
 * [1295] Find Numbers with Even Number of Digits
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
    pub fn find_numbers(nums: Vec<i32>) -> i32 {
        let mut count = 0;
        for num in nums {
            if (10..100).contains(&num) || (1_000..10_000).contains(&num) || (num == 100_000) {
                count += 1;
            }
        }
        count
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_numbers(vec![12, 345, 2, 6, 7896]), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_numbers(vec![555, 901, 482, 1771]), 1);
}
