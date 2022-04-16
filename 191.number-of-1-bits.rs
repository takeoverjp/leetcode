/*
 * @lc app=leetcode id=191 lang=rust
 *
 * [191] Number of 1 Bits
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
    pub fn hammingWeight(n: u32) -> i32 {
        let mut ret: i32 = 0;
        for i in 0..32 {
            ret += ((n >> i) & 1) as i32;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::hammingWeight(0b00000000000000000000000000001011),
        3
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::hammingWeight(0b00000000000000000000000010000000),
        1
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::hammingWeight(0b11111111111111111111111111111101),
        31
    );
}
