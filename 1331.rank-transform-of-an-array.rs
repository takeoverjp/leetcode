/*
 * @lc app=leetcode id=1331 lang=rust
 *
 * [1331] Rank Transform of an Array
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
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        let mut ret = arr.clone();
        ret.sort_unstable();
        let mut rank = std::collections::HashMap::<i32, i32>::new();
        for a in &ret {
            if rank.get(a) == None {
                rank.insert(*a, (rank.len() + 1) as i32);
            }
        }
        for i in 0..ret.len() {
            ret[i] = rank[&arr[i]];
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::array_rank_transform(vec![40, 10, 20, 30]),
        vec![4, 1, 2, 3]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::array_rank_transform(vec![100, 100, 100]),
        vec![1, 1, 1]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::array_rank_transform(vec![37, 12, 28, 9, 100, 56, 80, 5, 12]),
        vec![5, 3, 4, 2, 8, 6, 7, 1, 3]
    );
}
