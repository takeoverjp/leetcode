/*
 * @lc app=leetcode id=169 lang=rust
 *
 * [169] Majority Element
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
    pub fn majority_element(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut counts = std::collections::HashMap::new();
        for num in nums {
            let count = counts.entry(num).or_insert(0);
            *count += 1;
            if *count > len / 2 {
                return num;
            }
        }
        return -1;
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::majority_element(vec![3, 2, 3]), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::majority_element(vec![2, 2, 1, 1, 1, 2, 2]), 2);
}
