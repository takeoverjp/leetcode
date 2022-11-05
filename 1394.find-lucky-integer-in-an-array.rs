/*
 * @lc app=leetcode id=1394 lang=rust
 *
 * [1394] Find Lucky Integer in an Array
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
    pub fn find_lucky(arr: Vec<i32>) -> i32 {
        let mut hg = vec![];
        let mut freq = std::collections::HashMap::<i32, i32>::new();
        for i in arr {
            let f = freq.entry(i).or_insert(0);
            *f += 1;
        }
        for (key, val) in freq {
            if key == val {
                hg.push(key);
            }
        }
        if !hg.is_empty() {
            return *hg.iter().max().unwrap();
        }
        -1
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_lucky(vec![2, 2, 3, 4]), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_lucky(vec![1, 2, 2, 3, 3, 3]), 3);
}

#[test]
fn test3() {
    assert_eq!(Solution::find_lucky(vec![2, 2, 2, 3, 3]), -1);
}
