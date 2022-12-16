/*
 * @lc app=leetcode id=1588 lang=rust
 *
 * [1588] Sum of All Odd Length Subarrays
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
    pub fn sum_odd_length_subarrays(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut answer = 0;
        for left in 0..n {
            for right in left..n {
                if (right - left + 1) % 2 == 1 {
                    let mut current_sum = 0;
                    for elem in arr.iter().take(right + 1).skip(left) {
                        current_sum += elem;
                    }
                    answer += current_sum;
                }
            }
        }
        answer
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::sum_odd_length_subarrays(vec![1, 4, 2, 5, 3]), 58);
}

#[test]
fn test2() {
    assert_eq!(Solution::sum_odd_length_subarrays(vec![1, 2]), 3);
}

#[test]
fn test3() {
    assert_eq!(Solution::sum_odd_length_subarrays(vec![10, 11, 12]), 66);
}
