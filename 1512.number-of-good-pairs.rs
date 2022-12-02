/*
 * @lc app=leetcode id=1512 lang=rust
 *
 * [1512] Number of Good Pairs
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
    pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let mut count = std::collections::HashMap::<i32, i32>::new();
        for num in nums {
            let c = count.entry(num).or_insert(0);
            res += *c;
            *c += 1;
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::num_identical_pairs(vec![1, 2, 3, 1, 1, 3]), 4);
}

#[test]
fn test2() {
    assert_eq!(Solution::num_identical_pairs(vec![1, 1, 1, 1]), 6);
}
#[test]
fn test3() {
    assert_eq!(Solution::num_identical_pairs(vec![1, 2, 3]), 0);
}
