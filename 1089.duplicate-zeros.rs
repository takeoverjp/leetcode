/*
 * @lc app=leetcode id=1089 lang=rust
 *
 * [1089] Duplicate Zeros
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
    pub fn duplicate_zeros(arr: &mut Vec<i32>) {
        let n = arr.len();
        let mut j = n + arr.iter().filter(|&n| *n == 0).count();
        let mut i = n - 1;
        loop {
            j -= 1;
            if j < n {
                arr[j] = arr[i];
            }
            if arr[i] == 0 {
                j -= 1;
                if j < n {
                    arr[j] = 0;
                }
            }
            if i == 0 {
                break;
            }
            i -= 1;
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    let mut arr = vec![1, 0, 2, 3, 0, 4, 5, 0];
    Solution::duplicate_zeros(&mut arr);
    assert_eq!(arr, vec![1, 0, 0, 2, 3, 0, 0, 4]);
}

#[test]
fn test2() {
    let mut arr = vec![1, 2, 3];
    Solution::duplicate_zeros(&mut arr);
    assert_eq!(arr, vec![1, 2, 3]);
}
