/*
 * @lc app=leetcode id=290 lang=rust
 *
 * [290] Word Pattern
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
    pub fn word_pattern(pattern: String, s: String) -> bool {
        let words = s.split(' ').collect::<Vec<&str>>();
        if pattern.len() != words.len() {
            return false;
        }

        let mut map = std::collections::HashMap::<char, &str>::new();
        let mut rmap = std::collections::HashMap::<&str, char>::new();
        for (idx, word) in words.iter().enumerate() {
            if idx >= pattern.len() {
                return false;
            }
            let c = pattern.chars().nth(idx).unwrap();
            match map.get(&c) {
                Some(w) => {
                    if *w != *word {
                        return false;
                    }
                }
                None => {
                    map.insert(c, word);
                }
            }
            match rmap.get(word) {
                Some(rc) => {
                    if *rc != c {
                        return false;
                    }
                }
                None => {
                    rmap.insert(word, c);
                }
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::word_pattern(
        "abba".to_string(),
        "dog cat cat dog".to_string()
    ));
}

#[test]
fn test2() {
    assert!(!Solution::word_pattern(
        "abba".to_string(),
        "dog cat cat fish".to_string()
    ));
}

#[test]
fn test3() {
    assert!(!Solution::word_pattern(
        "aaaa".to_string(),
        "dog cat cat dog".to_string()
    ));
}

#[test]
fn test4() {
    assert!(!Solution::word_pattern(
        "abba".to_string(),
        "dog dog dog dog".to_string()
    ));
}

#[test]
fn test5() {
    assert!(!Solution::word_pattern(
        "aaa".to_string(),
        "dog dog dog dog".to_string()
    ));
}

#[test]
fn test6() {
    assert!(!Solution::word_pattern(
        "jquery".to_string(),
        "jquery".to_string()
    ));
}
