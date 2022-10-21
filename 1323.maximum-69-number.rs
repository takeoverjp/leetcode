/*
 * @lc app=leetcode id=1323 lang=rust
 *
 * [1323] Maximum 69 Number
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
    pub fn maximum69_number(num: i32) -> i32 {
        let mut s_num: Vec<char> = num.to_string().chars().collect();
        for c in &mut s_num {
            if *c == '6' {
                *c = '9';
                break;
            }
        }
        s_num.iter().collect::<String>().parse::<i32>().unwrap()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::maximum69_number(9669), 9969);
}

#[test]
fn test2() {
    assert_eq!(Solution::maximum69_number(9996), 9999);
}

#[test]
fn test3() {
    assert_eq!(Solution::maximum69_number(9999), 9999);
}
