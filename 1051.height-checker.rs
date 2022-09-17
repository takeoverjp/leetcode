/*
 * @lc app=leetcode id=1051 lang=rust
 *
 * [1051] Height Checker
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
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut height_to_freq = [0; 101];
        for height in &heights {
            height_to_freq[*height as usize] += 1;
        }
        let mut result = 0;
        let mut cur_height: i32 = 0;
        for height in heights {
            while height_to_freq[cur_height as usize] == 0 {
                cur_height += 1;
            }
            if cur_height != height {
                result += 1;
            }
            height_to_freq[cur_height as usize] -= 1;
        }
        result
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::height_checker(vec![1, 1, 4, 2, 1, 3]), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::height_checker(vec![5, 1, 2, 3, 4]), 5);
}

#[test]
fn test3() {
    assert_eq!(Solution::height_checker(vec![1, 2, 3, 4, 5]), 0);
}
