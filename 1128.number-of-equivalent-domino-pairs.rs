/*
 * @lc app=leetcode id=1128 lang=rust
 *
 * [1128] Number of Equivalent Domino Pairs
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
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut count = std::collections::HashMap::<i32, i32>::new();
        let mut ret = 0;
        for d in dominoes {
            let idx = i32::min(d[0], d[1]) * 10 + i32::max(d[0], d[1]);
            let c = count.entry(idx).or_insert(0);
            ret += *c;
            *c += 1;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::num_equiv_domino_pairs(vec![vec![1, 2], vec![2, 1], vec![3, 4], vec![5, 6]]),
        1
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::num_equiv_domino_pairs(vec![
            vec![1, 2],
            vec![1, 2],
            vec![1, 1],
            vec![1, 2],
            vec![2, 2]
        ]),
        3
    );
}
