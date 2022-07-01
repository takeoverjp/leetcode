/*
 * @lc app=leetcode id=594 lang=rust
 *
 * [594] Longest Harmonious Subsequence
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
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut counts = std::collections::HashMap::<i32, i32>::new();
        nums.iter()
            .for_each(|&num| *counts.entry(num).or_insert(0) += 1);
        counts.iter().fold(0, |acc, (&num, &count)| {
            counts
                .get(&(num + 1))
                .map_or(acc, |c| std::cmp::max(acc, count + c))
        })
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_lhs(vec![1, 3, 2, 2, 5, 2, 3, 7]), 5);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_lhs(vec![1, 2, 3, 4]), 2);
}

#[test]
fn test3() {
    assert_eq!(Solution::find_lhs(vec![1, 1, 1, 1]), 0);
}
