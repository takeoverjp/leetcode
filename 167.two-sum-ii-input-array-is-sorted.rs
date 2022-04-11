/*
 * @lc app=leetcode id=167 lang=rust
 *
 * [167] Two Sum II - Input Array Is Sorted
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

#[macro_export]
macro_rules! list_node {
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        for i in 0..numbers.len() {
            let rest = target - numbers[i];
            match numbers[(i + 1)..].binary_search(&rest) {
                Err(..) => continue,
                Ok(index) => return vec![i as i32 + 1, (i + 1 + index) as i32 + 1],
            }
        }
        vec![]
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::two_sum(vec![2, 7, 11, 15], 9), vec![1, 2]);
}

#[test]
fn test2() {
    assert_eq!(Solution::two_sum(vec![2, 3, 4], 6), vec![1, 3]);
}

#[test]
fn test3() {
    assert_eq!(Solution::two_sum(vec![-1, 0], -1), vec![1, 2]);
}
