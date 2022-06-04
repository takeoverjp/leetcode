/*
 * @lc app=leetcode id=414 lang=rust
 *
 * [414] Third Maximum Number
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
    pub fn third_max(nums: Vec<i32>) -> i32 {
        let mut maxes = vec![i64::MIN, i64::MIN, i64::MIN];
        for curr in nums {
            for j in 0..3 {
                if curr as i64 == maxes[j] {
                    break;
                }
                if curr as i64 > maxes[j] {
                    let mut k = 2;
                    loop {
                        if k <= j {
                            break;
                        }
                        maxes[k] = maxes[k - 1];
                        k -= 1;
                    }
                    maxes[j] = curr as i64;
                    break;
                }
            }
        }
        if maxes[2] == i64::MIN {
            return maxes[0] as i32;
        }
        maxes[2] as i32
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::third_max(vec![1, 2]), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::third_max(vec![2, 2, 3, 1]), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::third_max(vec![3, 2, 1]), 1);
}
