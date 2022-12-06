/*
 * @lc app=leetcode id=1534 lang=rust
 *
 * [1534] Count Good Triplets
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
    pub fn count_good_triplets(arr: Vec<i32>, a: i32, b: i32, c: i32) -> i32 {
        let mut count = 0;
        for i in 0..arr.len() {
            for j in (i + 1)..arr.len() {
                if (arr[i] - arr[j]).abs() <= a {
                    for k in (j + 1)..arr.len() {
                        let new_b = (arr[j] - arr[k]).abs();
                        let new_c = (arr[k] - arr[i]).abs();
                        if new_b <= b && new_c <= c {
                            count += 1;
                        }
                    }
                }
            }
        }
        count
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::count_good_triplets(vec![3, 0, 1, 1, 9, 7], 7, 2, 3),
        4
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::count_good_triplets(vec![1, 1, 2, 2, 3], 0, 0, 1),
        0
    );
}
