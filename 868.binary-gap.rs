/*
 * @lc app=leetcode id=868 lang=rust
 *
 * [868] Binary Gap
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

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
    pub right: Option<std::rc::Rc<std::cell::RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

#[macro_export]
macro_rules! list_node {
    () => {
        None
    };
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut ret = 0;
        let mut count = 0;
        let mut last = -1;
        while n > (0b1 << count) {
            if n & (0b1 << count) != 0 {
                if last < 0 {
                    last = count;
                } else {
                    ret = ret.max(count - last);
                    last = count;
                }
            }
            count += 1;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::binary_gap(0b10110), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::binary_gap(0b1000), 0);
    assert_eq!(Solution::binary_gap(0b101), 2);
}
