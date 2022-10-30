/*
 * @lc app=leetcode id=1365 lang=rust
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
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
    pub fn smaller_numbers_than_current(nums: Vec<i32>) -> Vec<i32> {
        let mut answer = vec![];
        let mut count = [0; 101];
        let len = nums.len();
        for i in 0..len {
            count[nums[i] as usize] += 1;
        }
        for i in 1..101 {
            count[i] += count[i - 1];
        }
        for i in 0..len {
            if nums[i] == 0 {
                answer.push(0);
            } else {
                answer.push(count[nums[i] as usize - 1]);
            }
        }
        answer
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::smaller_numbers_than_current(vec![8, 1, 2, 2, 3]),
        vec![4, 0, 1, 1, 3]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::smaller_numbers_than_current(vec![6, 5, 4, 8]),
        vec![2, 1, 0, 3]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::smaller_numbers_than_current(vec![7, 7, 7, 7]),
        vec![0, 0, 0, 0]
    );
}
