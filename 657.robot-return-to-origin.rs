/*
 * @lc app=leetcode id=657 lang=rust
 *
 * [657] Robot Return to Origin
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
    pub fn judge_circle(moves: String) -> bool {
        let mut x = 0;
        let mut y = 0;
        for c in moves.chars() {
            match c {
                'U' => {
                    y += 1;
                }
                'D' => {
                    y -= 1;
                }
                'L' => {
                    x -= 1;
                }
                'R' => {
                    x += 1;
                }
                _ => {}
            }
        }
        x == 0 && y == 0
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::judge_circle("UD".to_string()));
}

#[test]
fn test2() {
    assert!(!Solution::judge_circle("LL".to_string()));
}
