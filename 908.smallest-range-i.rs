/*
 * @lc app=leetcode id=908 lang=rust
 *
 * [908] Smallest Range I
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
    pub fn smallest_range_i(nums: Vec<i32>, k: i32) -> i32 {
        if nums.is_empty() {
            return 0;
        }
        let mut min_num = i32::MAX;
        let mut max_num = i32::MIN;
        for num in nums {
            min_num = min_num.min(num);
            max_num = max_num.max(num);
        }
        let diff = max_num - min_num;
        if k * 2 >= diff {
            return 0;
        }
        diff - k * 2
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::smallest_range_i(vec![1], 0), 0);
}

#[test]
fn test2() {
    assert_eq!(Solution::smallest_range_i(vec![0, 10], 2), 6);
}

#[test]
fn test3() {
    assert_eq!(Solution::smallest_range_i(vec![1, 3, 6], 3), 0);
}
