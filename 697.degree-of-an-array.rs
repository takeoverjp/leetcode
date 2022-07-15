/*
 * @lc app=leetcode id=697 lang=rust
 *
 * [697] Degree of an Array
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
    pub fn find_shortest_sub_array(nums: Vec<i32>) -> i32 {
        use std::cmp::Ordering::*;

        let (mut degree, mut min_len) = (1, 1);
        let (mut counter, mut indicies) = ([0; 50_000], [-1; 50_000]);

        for (x, ind) in nums.iter().map(|&x| x as usize).zip(0..) {
            let (num, first) = (&mut counter[x], &mut indicies[x]);
            let cur_len = ind - *first + 1;

            *num += 1;
            if *first == -1 {
                *first = ind;
            }

            match degree.cmp(num) {
                Less => {
                    degree = *num;
                    min_len = cur_len;
                }
                Equal if cur_len < min_len => min_len = cur_len,
                _ => (),
            }
        }
        min_len
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_shortest_sub_array(vec![1, 2, 2, 3, 1]), 2);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_shortest_sub_array(vec![1, 2, 2, 3, 1, 4, 2]),
        6
    );
}
