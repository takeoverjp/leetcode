/*
 * @lc app=leetcode id=1560 lang=rust
 *
 * [1560] Most Visited Sector in  a Circular Track
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
    pub fn most_visited(n: i32, rounds: Vec<i32>) -> Vec<i32> {
        let mut res = vec![];
        for i in rounds[0]..=rounds[rounds.len() - 1] {
            res.push(i);
        }
        if !res.is_empty() {
            return res;
        }
        for i in 1..=rounds[rounds.len() - 1] {
            res.push(i);
        }
        for i in rounds[0]..=n {
            res.push(i)
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::most_visited(4, vec![1, 3, 1, 2]), vec![1, 2]);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::most_visited(2, vec![2, 1, 2, 1, 2, 1, 2, 1, 2]),
        vec![2]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::most_visited(7, vec![1, 3, 5, 7]),
        vec![1, 2, 3, 4, 5, 6, 7]
    );
}
