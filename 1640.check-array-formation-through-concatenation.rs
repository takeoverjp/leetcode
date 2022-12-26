/*
 * @lc app=leetcode id=1640 lang=rust
 *
 * [1640] Check Array Formation Through Concatenation
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
    pub fn can_form_array(arr: Vec<i32>, pieces: Vec<Vec<i32>>) -> bool {
        let mut mp = std::collections::HashMap::<i32, Vec<i32>>::new();
        let n = arr.len();
        for piece in pieces {
            mp.insert(piece[0], piece);
        }

        let mut i = 0;
        while i < n {
            if !mp.contains_key(&arr[i]) {
                return false;
            }

            for num in &mp[&arr[i]] {
                if *num != arr[i] {
                    return false;
                }
                i += 1;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::can_form_array(
        vec![15, 88],
        vec![vec![88], vec![15]]
    ));
}

#[test]
fn test2() {
    assert!(!Solution::can_form_array(
        vec![49, 18, 16],
        vec![vec![16, 18, 49]]
    ));
}

#[test]
fn test3() {
    assert!(Solution::can_form_array(
        vec![91, 4, 64, 78],
        vec![vec![78], vec![4, 64], vec![91]]
    ));
}
