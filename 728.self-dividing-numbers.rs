/*
 * @lc app=leetcode id=728 lang=rust
 *
 * [728] Self Dividing Numbers
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
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        let mut ret = vec![];
        for i in left..=right {
            if Solution::self_dividable(i) {
                ret.push(i);
            }
        }
        ret
    }

    fn self_dividable(num: i32) -> bool {
        if num < 9 {
            return true;
        }
        let mut i = num;
        while i > 0 {
            if i % 10 == 0 {
                return false;
            }
            if num % (i % 10) != 0 {
                return false;
            }
            i /= 10;
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::self_dividing_numbers(1, 22),
        vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 12, 15, 22]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::self_dividing_numbers(47, 85),
        vec![48, 55, 66, 77]
    );
}
