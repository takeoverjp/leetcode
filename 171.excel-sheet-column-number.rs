/*
 * @lc app=leetcode id=171 lang=rust
 *
 * [171] Excel Sheet Column Number
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
    pub fn title_to_number(column_title: String) -> i32 {
        let mut ret = 0;
        for c in column_title.chars() {
            let num = (c as i32) - ('A' as i32) + 1;
            ret = ret * 26 + num;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::title_to_number("A".to_string()), 1);
}

#[test]
fn test2() {
    assert_eq!(Solution::title_to_number("AB".to_string()), 28);
}

#[test]
fn test3() {
    assert_eq!(Solution::title_to_number("ZY".to_string()), 701);
}
