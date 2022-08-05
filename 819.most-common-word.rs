/*
 * @lc app=leetcode id=819 lang=rust
 *
 * [819] Most Common Word
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
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        use std::collections::HashMap;
        let mut freq = HashMap::new();

        paragraph
            .split(|ch: char| ch.is_ascii_punctuation() || ch.is_ascii_whitespace())
            .for_each(|word| {
                let word = word.to_ascii_lowercase();
                if !word.is_empty() && !banned.contains(&word) {
                    *freq.entry(word).or_insert(0) += 1;
                }
            });
        freq.iter()
            .max_by(|a, b| a.1.cmp(&b.1))
            .map(|(k, _)| k.to_owned())
            .unwrap()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::most_common_word(
            "Bob hit a ball, the hit BALL flew far after it was hit.".to_string(),
            vec!["hit".to_string()]
        ),
        "ball".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::most_common_word("a.".to_string(), vec![]),
        "a".to_string()
    );
}
