/*
 * @lc app=leetcode id=482 lang=rust
 *
 * [482] License Key Formatting
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
    pub fn license_key_formatting(s: String, k: i32) -> String {
        let mut ret = String::new();
        let mut dash_num = 0;
        for c in s.chars() {
            if c == '-' {
                dash_num += 1;
            }
        }
        let len = s.len() - dash_num;
        let mut part_len = (len - 1) % (k as usize) + 1;

        for c in s.chars() {
            if c == '-' {
                continue;
            }
            if part_len == 0 {
                ret = format!("{}{}", ret, '-');
                part_len = k as usize;
            }
            let mut capital_c = c;
            if c.is_lowercase() {
                capital_c = (c as u8 + b'A' - b'a') as char;
            }
            ret = format!("{}{}", ret, capital_c);
            part_len -= 1;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::license_key_formatting("5F3Z-2e-9-w".to_string(), 4),
        "5F3Z-2E9W".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::license_key_formatting("2-5g-3-J".to_string(), 2),
        "2-5G-3J".to_string()
    );
}
