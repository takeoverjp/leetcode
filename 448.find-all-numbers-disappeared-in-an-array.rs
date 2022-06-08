/*
 * @lc app=leetcode id=448 lang=rust
 *
 * [448] Find All Numbers Disappeared in an Array
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
    pub fn find_disappeared_numbers(mut nums: Vec<i32>) -> Vec<i32> {
        let len = nums.len();
        for i in 0..len {
            let index = nums[i].abs() - 1;
            if nums[index as usize] > 0 {
                nums[index as usize] *= -1;
            }
        }
        let mut ret = Vec::<i32>::new();
        for (i, num) in nums.iter().enumerate() {
            if *num > 0 {
                ret.push((i + 1) as i32);
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_disappeared_numbers(vec![4, 3, 2, 7, 8, 2, 3, 1]),
        vec![5, 6]
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::find_disappeared_numbers(vec![1, 1]), vec![2]);
}
