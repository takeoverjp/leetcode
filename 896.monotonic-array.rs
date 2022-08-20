/*
 * @lc app=leetcode id=896 lang=rust
 *
 * [896] Monotonic Array
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
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        let mut is_increasing: Option<bool> = None;
        let mut last = nums[0];
        for num in nums.into_iter().skip(1) {
            if num == last {
                continue;
            }
            if let Some(increasing) = is_increasing {
                if increasing {
                    if num < last {
                        return false;
                    }
                } else if num > last {
                    return false;
                }
            } else {
                is_increasing = Some(num > last);
            }
            last = num;
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_monotonic(vec![1, 2, 2, 3]));
}

#[test]
fn test2() {
    assert!(Solution::is_monotonic(vec![6, 5, 4, 4]));
    assert!(!Solution::is_monotonic(vec![1, 3, 2]));
}
