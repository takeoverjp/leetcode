/*
 * @lc app=leetcode id=1385 lang=rust
 *
 * [1385] Find the Distance Value Between Two Arrays
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
    pub fn find_the_distance_value(arr1: Vec<i32>, arr2: Vec<i32>, d: i32) -> i32 {
        let mut ret = 0;
        for a in arr1 {
            let mut found = false;
            for b in &arr2 {
                if (a - b).abs() <= d {
                    found = true;
                    break;
                }
            }
            if !found {
                ret += 1;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_the_distance_value(vec![4, 5, 8], vec![10, 9, 1, 8], 2),
        2
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_the_distance_value(vec![1, 4, 2, 3], vec![-4, -3, 6, 10, 20, 30], 3),
        2
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::find_the_distance_value(vec![2, 1, 100, 3], vec![-5, -2, 10, -3, 7], 6),
        1
    );
}
