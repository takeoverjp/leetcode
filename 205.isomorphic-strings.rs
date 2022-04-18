/*
 * @lc app=leetcode id=205 lang=rust
 *
 * [205] Isomorphic Strings
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

#[macro_export]
macro_rules! list_node {
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut s2t = HashMap::new();
        let mut t2s = HashMap::new();
        for (idx, sc) in s.char_indices() {
            let tc = t.chars().nth(idx).unwrap();
            match s2t.get(&sc) {
                Some(expected) => {
                    if *expected == tc {
                        continue;
                    } else {
                        return false;
                    }
                }
                _ => {
                    s2t.insert(sc, tc);
                }
            }
            match t2s.get(&tc) {
                Some(expected) => {
                    if *expected == sc {
                        continue;
                    } else {
                        return false;
                    }
                }
                _ => {
                    t2s.insert(tc, sc);
                }
            }
        }
        return true;
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_isomorphic(
        "egg".to_string(),
        "add".to_string()
    ));
}

#[test]
fn test2() {
    assert!(!Solution::is_isomorphic(
        "foo".to_string(),
        "bar".to_string()
    ));
}

#[test]
fn test3() {
    assert!(Solution::is_isomorphic(
        "paper".to_string(),
        "title".to_string()
    ));
}

#[test]
fn test4() {
    assert!(!Solution::is_isomorphic(
        "badc".to_string(),
        "baba".to_string()
    ));
}
