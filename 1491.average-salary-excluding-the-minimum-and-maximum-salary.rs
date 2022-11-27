/*
 * @lc app=leetcode id=1491 lang=rust
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
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
    pub fn average(salary: Vec<i32>) -> f64 {
        if salary.len() == 2 {
            return 0.0;
        }
        let mut mins = i32::MAX;
        let mut maxs = i32::MIN;
        let mut sum: f64 = 0.0;
        for x in &salary {
            mins = mins.min(*x);
            maxs = maxs.max(*x);
            sum += *x as f64;
        }
        (sum - (mins + maxs) as f64) / (salary.len() - 2) as f64
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::average(vec![4000, 3000, 1000, 2000]), 2500.00000);
}

#[test]
fn test2() {
    assert_eq!(Solution::average(vec![1000, 2000, 3000]), 2000.00000);
}
