/*
 * @lc app=leetcode id=643 lang=rust
 *
 * [643] Maximum Average Subarray I
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
    pub fn find_max_average(nums: Vec<i32>, k: i32) -> f64 {
        let mut max = i32::MIN;
        let size = nums.len();
        let mut sum = 0;
        for i in 0..k {
            sum += nums[i as usize];
        }
        max = max.max(sum);
        for i in 1..(size - k as usize + 1) {
            sum = sum - nums[i - 1] + nums[i + k as usize - 1];
            max = max.max(sum);
        }
        (max as f64) / (k as f64)
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_max_average(vec![1, 12, -5, -6, 50, 3], 4),
        12.75
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::find_max_average(vec![5], 1), 5.0);
}
