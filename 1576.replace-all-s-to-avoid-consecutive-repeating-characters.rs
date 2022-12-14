/*
 * @lc app=leetcode id=1576 lang=rust
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
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
    pub fn modify_string(s: String) -> String {
        let mut s = s.chars().collect::<Vec<char>>();
        for i in 0..s.len() {
            if s[i] == '?' {
                s[i] = 'a';
                while s[i] <= 'c' {
                    if (i == 0 || s[i - 1] != s[i]) && (i == s.len() - 1 || s[i + 1] != s[i]) {
                        break;
                    }
                    s[i] = ((s[i] as u8) + 1) as char
                }
            }
        }
        s.iter().collect::<String>()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::modify_string("?zs".to_string()),
        "azs".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::modify_string("ubv?w".to_string()),
        "ubvaw".to_string()
    );
}
