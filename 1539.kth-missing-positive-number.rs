/*
 * @lc app=leetcode id=1539 lang=rust
 *
 * [1539] Kth Missing Positive Number
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
    pub fn find_kth_positive(arr: Vec<i32>, k: i32) -> i32 {
        let mut low = 0;
        let mut high = arr.len() - 1;
        let mut mid;
        while low <= high {
            mid = (low + high) / 2;
            if arr[mid] - (1 + mid as i32) < k {
                low = mid + 1;
            } else {
                if low == high {
                    break;
                }
                high = mid.saturating_sub(1);
            }
        }
        low as i32 + k
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_kth_positive(vec![2, 3, 4, 7, 11], 5), 9);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_kth_positive(vec![1, 2, 3, 4], 2), 6);
}

#[test]
fn test3() {
    assert_eq!(Solution::find_kth_positive(vec![2], 1), 1);
}

#[test]
fn test4() {
    assert_eq!(Solution::find_kth_positive(vec![3, 10], 2), 2);
}
