/*
 * @lc app=leetcode id=1694 lang=rust
 *
 * [1694] Reformat Phone Number
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
    pub fn reformat_number(number: String) -> String {
        let mut reformatted = "".to_string();
        for c in number.chars() {
            if c.is_ascii_digit() {
                reformatted += &c.to_string();
            }
        }
        let ret = Solution::get_groups(reformatted);
        reformatted = "".to_string();
        for (i, item) in ret.iter().enumerate() {
            if i != 0 {
                reformatted += "-";
            }
            reformatted += item;
        }
        reformatted
    }

    fn get_groups(s: String) -> Vec<String> {
        if s.len() <= 3 {
            return vec![s];
        }
        if s.len() == 4 {
            return vec![s[0..2].to_string(), s[2..].to_string()];
        }
        let mut ret = vec![s[0..3].to_string()];
        let r = Solution::get_groups(s[3..].to_string());
        for t in r {
            ret.push(t);
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reformat_number("1-23-45 6".to_string()),
        "123-456".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reformat_number("123 4-567".to_string()),
        "123-45-67".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::reformat_number("123 4-5678".to_string()),
        "123-456-78".to_string()
    );
}
