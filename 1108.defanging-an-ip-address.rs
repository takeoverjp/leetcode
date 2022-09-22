/*
 * @lc app=leetcode id=1108 lang=rust
 *
 * [1108] Defanging an IP Address
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
    pub fn defang_i_paddr(address: String) -> String {
        let mut ret = "".to_string();
        for c in address.chars() {
            if c == '.' {
                ret += "[.]";
            } else {
                ret += &c.to_string();
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::defang_i_paddr("1.1.1.1".to_string()),
        "1[.]1[.]1[.]1".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::defang_i_paddr("255.100.50.0".to_string()),
        "255[.]100[.]50[.]0".to_string()
    );
}
