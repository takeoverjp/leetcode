/*
 * @lc app=leetcode id=859 lang=rust
 *
 * [859] Buddy Strings
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
    pub fn buddy_strings(s: String, goal: String) -> bool {
        if s.len() != goal.len() {
            return false;
        }
        if s == goal {
            return s
                .chars()
                .fold(
                    std::collections::HashMap::<char, usize>::new(),
                    |mut m, count| {
                        *m.entry(count).or_default() += 1;
                        m
                    },
                )
                .into_iter()
                .any(|(_, v)| v > 1);
        }

        let mut state = 0;
        let mut last_pair = (0, 0);
        s.as_bytes()
            .iter()
            .zip(goal.as_bytes())
            .filter(|(&sc, &gc)| sc != gc)
            .try_for_each(|(&sc, &gc)| match state {
                0 => {
                    last_pair = (sc, gc);
                    state = 1;
                    Ok(())
                }
                1 if last_pair.0 == gc && last_pair.1 == sc => {
                    state = 2;
                    Ok(())
                }
                _ => {
                    state = 0;
                    Err(())
                }
            });
        state == 2
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::buddy_strings("ab".to_string(), "ba".to_string()));
}

#[test]
fn test2() {
    assert!(!Solution::buddy_strings("ab".to_string(), "ab".to_string()));
}

#[test]
fn test3() {
    assert!(Solution::buddy_strings("aa".to_string(), "aa".to_string()));
}

#[test]
fn test4() {
    assert!(!Solution::buddy_strings(
        "abcd".to_string(),
        "badc".to_string()
    ));
}
