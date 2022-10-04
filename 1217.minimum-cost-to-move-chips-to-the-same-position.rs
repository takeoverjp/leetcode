/*
 * @lc app=leetcode id=1217 lang=rust
 *
 * [1217] Minimum Cost to Move Chips to The Same Position
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
    pub fn min_cost_to_move_chips(position: Vec<i32>) -> i32 {
        let mut cnt = [0; 2];
        for p in position {
            cnt[(p % 2) as usize] += 1;
        }
        i32::min(cnt[0], cnt[1])
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::min_cost_to_move_chips(vec![1, 2, 3]), 1);
}

#[test]
fn test2() {
    assert_eq!(Solution::min_cost_to_move_chips(vec![2, 2, 2, 3, 3]), 2);
}

#[test]
fn test3() {
    assert_eq!(Solution::min_cost_to_move_chips(vec![1, 1000000000]), 1);
}
