/*
 * @lc app=leetcode id=1470 lang=rust
 *
 * [1470] Shuffle the Array
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
    pub fn shuffle(mut nums: Vec<i32>, n: i32) -> Vec<i32> {
        let len = nums.len();
        let n = n as usize;
        for i in n..len {
            nums[i] = (nums[i] * 1024) + nums[i - n];
        }

        let mut index = 0;
        for i in n..len {
            nums[index] = nums[i] % 1024;
            nums[index + 1] = nums[i] / 1024;
            index += 2;
        }
        nums
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::shuffle(vec![2, 5, 1, 3, 4, 7], 3),
        vec![2, 3, 5, 4, 1, 7]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::shuffle(vec![1, 2, 3, 4, 4, 3, 2, 1], 4),
        vec![1, 4, 2, 3, 3, 2, 4, 1]
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::shuffle(vec![1, 1, 2, 2], 2), vec![1, 2, 1, 2]);
}
