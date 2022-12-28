/*
 * @lc app=leetcode id=1646 lang=rust
 *
 * [1646] Get Maximum in Generated Array
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
    pub fn get_maximum_generated(n: i32) -> i32 {
        let n = n as usize;
        let mut arr = vec![0; n + 2];
        arr[1] = 1;
        for i in 1usize..n {
            if 2 * i <= n {
                arr[2 * i] = arr[i];
            }
            if 2 * i < n {
                arr[2 * i + 1] = arr[i] + arr[i + 1];
            }
        }
        if n == 0 {
            return 0;
        }

        *arr.iter().max().unwrap()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::get_maximum_generated(7), 3);
}

#[test]
fn test2() {
    assert_eq!(Solution::get_maximum_generated(2), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::get_maximum_generated(3), 2);
}
