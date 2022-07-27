/*
 * @lc app=leetcode id=747 lang=rust
 *
 * [747] Largest Number At Least Twice of Others
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
    pub fn dominant_index(nums: Vec<i32>) -> i32 {
        let size = nums.len();
        if size < 2 {
            return 0;
        }
        let mut largest = i32::MIN;
        let mut largest_idx: i32 = -1;
        let mut second = i32::MIN;
        for i in 0..size {
            if nums[i] >= largest {
                second = largest;
                largest = nums[i];
                largest_idx = i as i32;
            } else if nums[i] > second {
                second = nums[i];
            }
        }
        if largest as i64 >= 2 * second as i64 {
            largest_idx
        } else {
            -1
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::dominant_index(vec![3, 6, 1, 0]), 1);
}

#[test]
fn test2() {
    assert_eq!(Solution::dominant_index(vec![1, 2, 3, 4]), -1);
}
