/*
 * @lc app=leetcode id=202 lang=rust
 *
 * [202] Happy Number
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
    pub fn is_happy(n: i32) -> bool {
        let mut fast = Solution::next(n);
        let mut slow = n;
        while fast != slow {
            fast = Solution::next(Solution::next(fast));
            slow = Solution::next(slow);
        }
        fast == 1
    }

    fn next(mut n: i32) -> i32 {
        let mut ret = 0;
        while n > 0 {
            let digit = n % 10;
            ret += digit * digit;
            n /= 10;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_happy(19));
}

#[test]
fn test2() {
    assert!(!Solution::is_happy(2));
}
