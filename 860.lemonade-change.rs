/*
 * @lc app=leetcode id=860 lang=rust
 *
 * [860] Lemonade Change
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
    pub fn lemonade_change(bills: Vec<i32>) -> bool {
        let mut counts = [0; 2];
        for bill in bills {
            match bill {
                5 => {
                    counts[0] += 1;
                }
                10 => {
                    if counts[0] == 0 {
                        return false;
                    }
                    counts[1] += 1;
                    counts[0] -= 1;
                }
                20 => {
                    if counts[0] < 3 && (counts[0] < 1 || counts[1] < 1) {
                        return false;
                    }
                    if counts[1] > 0 {
                        counts[1] -= 1;
                        counts[0] -= 1;
                    } else {
                        counts[0] -= 3;
                    }
                }
                _ => {}
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::lemonade_change(vec![5, 5, 5, 10, 20]));
}

#[test]
fn test2() {
    assert!(!Solution::lemonade_change(vec![5, 5, 10, 10, 20]));
    assert!(!Solution::lemonade_change(vec![
        5, 5, 5, 10, 5, 5, 10, 20, 20, 20
    ]));
}
