/*
 * @lc app=leetcode id=415 lang=rust
 *
 * [415] Add Strings
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
    pub fn add_strings(num1: String, num2: String) -> String {
        let len1 = num1.len();
        let len2 = num2.len();
        let max_len = usize::max(len1, len2);
        let mut carry = 0;
        let mut ret = Vec::with_capacity(max_len + 1);
        let mut i: usize = 0;
        while i < max_len || carry > 0 {
            let mut dig1 = 0;
            let mut dig2 = 0;
            if i < len1 {
                dig1 = num1.chars().nth(len1 - i - 1).unwrap() as u8 - b'0';
            }
            if i < len2 {
                dig2 = num2.chars().nth(len2 - i - 1).unwrap() as u8 - b'0';
            }
            let sum = dig1 + dig2 + carry;
            carry = sum / 10;
            ret.push((b'0' + sum % 10) as char);
            i += 1;
        }
        ret.iter().rev().collect()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::add_strings("11".to_string(), "123".to_string()),
        "134".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::add_strings("456".to_string(), "77".to_string()),
        "533".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::add_strings("0".to_string(), "0".to_string()),
        "0".to_string()
    );
}
