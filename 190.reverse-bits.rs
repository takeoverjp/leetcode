/*
 * @lc app=leetcode id=190 lang=rust
 *
 * [190] Reverse Bits
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
    pub fn reverse_bits(x: u32) -> u32 {
        let mut ret = 0u32;
        for i in 0..32 {
            ret |= ((x >> i) & 1u32) << (31 - i);
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reverse_bits(0b00000010100101000001111010011100),
        0b00111001011110000010100101000000
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reverse_bits(0b11111111111111111111111111111101),
        0b10111111111111111111111111111111
    );
}
