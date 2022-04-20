/*
 * @lc app=leetcode id=219 lang=rust
 *
 * [219] Contains Duplicate II
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
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        let mut set = std::collections::HashSet::<i32>::new();
        for (idx, num) in nums.iter().enumerate() {
            if idx > k {
                set.remove(&nums[idx - k - 1]);
            }
            if !set.insert(nums[idx]) {
                return true;
            }
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::contains_nearby_duplicate(vec![1, 2, 3, 1], 3));
}

#[test]
fn test2() {
    assert!(Solution::contains_nearby_duplicate(vec![1, 0, 1, 1], 1));
}

#[test]
fn test3() {
    assert!(!Solution::contains_nearby_duplicate(
        vec![1, 2, 3, 1, 2, 3],
        2
    ));
}
