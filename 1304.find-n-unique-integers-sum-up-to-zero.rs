/*
 * @lc app=leetcode id=1304 lang=rust
 *
 * [1304] Find N Unique Integers Sum up to Zero
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
    pub fn sum_zero(n: i32) -> Vec<i32> {
        let mut ret = vec![0; n as usize];
        for i in 0..n {
            ret[i as usize] = i * 2 - n + 1;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::sum_zero(5), vec![-7, -1, 1, 3, 4]);
}

#[test]
fn test2() {
    assert_eq!(Solution::sum_zero(3), vec![-1, 0, 1]);
}

#[test]
fn test3() {
    assert_eq!(Solution::sum_zero(1), vec![0]);
}
