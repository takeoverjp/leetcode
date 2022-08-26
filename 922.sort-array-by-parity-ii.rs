/*
 * @lc app=leetcode id=922 lang=rust
 *
 * [922] Sort Array By Parity II
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
    pub fn sort_array_by_parity_ii(mut nums: Vec<i32>) -> Vec<i32> {
        let (mut i, mut j) = (0, 1);
        while i < nums.len() && j < nums.len() {
            if i < nums.len() && nums[i] % 2 == 0 {
                i += 2;
            }
            if j < nums.len() && nums[j] % 2 == 1 {
                j += 2;
            }
            if i < nums.len() && j < nums.len() {
                nums.swap(i, j);
            }
        }
        nums
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::sort_array_by_parity_ii(vec![4, 2, 5, 7]),
        vec![4, 5, 2, 7]
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::sort_array_by_parity_ii(vec![2, 3]), vec![2, 3]);
}
