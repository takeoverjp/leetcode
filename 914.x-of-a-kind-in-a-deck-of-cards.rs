/*
 * @lc app=leetcode id=914 lang=rust
 *
 * [914] X of a Kind in a Deck of Cards
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
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        let mut counts = std::collections::HashMap::<i32, i32>::new();
        for num in deck {
            match counts.get_mut(&num) {
                Some(x) => *x += 1,
                None => {
                    counts.insert(num, 1);
                }
            }
        }
        let mut min_num = i32::MAX;
        for (_key, val) in counts.iter() {
            min_num = min_num.min(*val);
        }
        for i in 2..=min_num {
            let mut is_ok = true;
            for (_key, val) in counts.iter() {
                if *val % i != 0 {
                    is_ok = false;
                    break;
                }
            }
            if is_ok {
                return true;
            }
        }
        false
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::has_groups_size_x(vec![1, 2, 3, 4, 4, 3, 2, 1]));
}

#[test]
fn test2() {
    assert!(!Solution::has_groups_size_x(vec![1, 1, 1, 2, 2, 2, 3, 3]));
}
