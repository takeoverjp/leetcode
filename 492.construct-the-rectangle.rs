/*
 * @lc app=leetcode id=492 lang=rust
 *
 * [492] Construct the Rectangle
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
    pub fn construct_rectangle(area: i32) -> Vec<i32> {
        let mut ret = Vec::<i32>::new();
        let max = (area as f64).sqrt() as i32;
        for candidate in (1..=max).rev() {
            if area % candidate == 0 {
                ret.push(area / candidate);
                ret.push(candidate);
                break;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::construct_rectangle(4), vec![2, 2]);
}

#[test]
fn test2() {
    assert_eq!(Solution::construct_rectangle(37), vec![37, 1]);
}

#[test]
fn test3() {
    assert_eq!(Solution::construct_rectangle(122122), vec![427, 286]);
}
