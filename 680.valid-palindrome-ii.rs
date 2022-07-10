/*
 * @lc app=leetcode id=680 lang=rust
 *
 * [680] Valid Palindrome II
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
    pub fn valid_palindrome(s: String) -> bool {
        let mut left = 0;
        let mut right = s.len() - 1;
        let s = s.chars().collect::<Vec<char>>();
        while left < right {
            if s[left] == s[right] {
                left += 1;
                right -= 1;
                continue;
            }
            if Solution::is_palindrome(&s, left + 1, right) {
                return true;
            }
            return Solution::is_palindrome(&s, left, right - 1);
        }
        true
    }
    fn is_palindrome(s: &[char], mut left: usize, mut right: usize) -> bool {
        while left < right {
            if s[left] != s[right] {
                return false;
            }
            left += 1;
            right -= 1;
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::valid_palindrome("aba".to_string()));
}

#[test]
fn test2() {
    assert!(Solution::valid_palindrome("abca".to_string()));
}

#[test]
fn test3() {
    assert!(!Solution::valid_palindrome("abc".to_string()));
}
