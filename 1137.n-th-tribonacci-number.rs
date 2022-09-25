/*
 * @lc app=leetcode id=1137 lang=rust
 *
 * [1137] N-th Tribonacci Number
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
    pub fn tribonacci(n: i32) -> i32 {
        let mut dp = vec![0, 1, 1];
        let n = n as usize;
        for i in 3..=n {
            dp[i % 3] += dp[(i + 1) % 3] + dp[(i + 2) % 3];
        }
        dp[n % 3]
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::tribonacci(4), 4);
}

#[test]
fn test2() {
    assert_eq!(Solution::tribonacci(25), 1389537);
}
