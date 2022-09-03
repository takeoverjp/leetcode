/*
 * @lc app=leetcode id=997 lang=rust
 *
 * [997] Find the Town Judge
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
    pub fn find_judge(n: i32, trust: Vec<Vec<i32>>) -> i32 {
        let n = n as usize;
        let mut is_trust_anyone = Vec::<bool>::new();
        is_trust_anyone.resize(n, false);
        for t in &trust {
            is_trust_anyone[t[0] as usize - 1] = true;
        }
        let mut counts = Vec::<usize>::new();
        counts.resize(n, 0);
        for t in &trust {
            counts[t[1] as usize - 1] += 1;
        }
        for i in 0..n {
            if !is_trust_anyone[i] && counts[i] == n - 1 {
                return i as i32 + 1;
            }
        }
        -1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_judge(2, vec![vec![1, 2]]), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_judge(3, vec![vec![1, 3], vec![2, 3]]), 3);
}

#[test]
fn test3() {
    assert_eq!(
        Solution::find_judge(3, vec![vec![1, 3], vec![2, 3], vec![3, 1]]),
        -1
    );
}
