/*
 * @lc app=leetcode id=168 lang=rust
 *
 * [168] Excel Sheet Column Title
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
    pub fn convert_to_title(mut column_number: i32) -> String {
        let mut ret = String::new();
        let a = 'A' as u8;
        while column_number > 0 {
            let c = (a + ((column_number - 1) % 26) as u8) as char;
            ret.insert(0, c);
            column_number = (column_number - 1) / 26;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::convert_to_title(1), "A");
}

#[test]
fn test2() {
    assert_eq!(Solution::convert_to_title(28), "AB");
}

#[test]
fn test3() {
    assert_eq!(Solution::convert_to_title(701), "ZY");
}
