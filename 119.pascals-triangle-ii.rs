/*
 * @lc app=leetcode id=119 lang=rust
 *
 * [119] Pascal's Triangle II
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
    pub fn get_row(row_index: i32) -> Vec<i32> {
        let mut ret = Vec::new();
        ret.resize((row_index + 1) as usize, 1);
        if row_index <= 1 {
            return ret;
        }
        let mut work = Vec::new();
        work.resize((row_index + 1) as usize, 1);
        for i in 2..=row_index {
            for j in 0usize..(i as usize - 1) {
                ret[j + 1] = work[j] + work[j + 1];
            }
            work = ret.clone();
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::get_row(3), vec![1, 3, 3, 1]);
}

#[test]
fn test2() {
    assert_eq!(Solution::get_row(0), vec![1]);
}

#[test]
fn test3() {
    assert_eq!(Solution::get_row(1), vec![1, 1]);
}

#[test]
fn test4() {
    assert_eq!(Solution::get_row(4), vec![1, 4, 6, 4, 1]);
}

#[test]
fn test5() {
    assert_eq!(Solution::get_row(2), vec![1, 2, 1]);
}
