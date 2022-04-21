/*
 * @lc app=leetcode id=231 lang=rust
 *
 * [231] Power of Two
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
    pub fn is_power_of_two(mut n: i32) -> bool {
        while n > 0 {
            if n == 1 {
                return true;
            }
            if n % 2 != 0 {
                return false;
            }
            n /= 2;
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_power_of_two(1));
    assert!(Solution::is_power_of_two(16));
    assert!(!Solution::is_power_of_two(3));
}
