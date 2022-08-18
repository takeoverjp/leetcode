/*
 * @lc app=leetcode id=884 lang=rust
 *
 * [884] Uncommon Words from Two Sentences
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
    pub fn uncommon_from_sentences(s1: String, s2: String) -> Vec<String> {
        let mut map = std::collections::HashMap::new();

        s1.split(' ')
            .chain(s2.split(' '))
            .for_each(|s| *map.entry(s).or_insert(0) += 1);
        map.iter()
            .filter_map(|(key, val)| match *val == 1 {
                true => Some((*key).to_string()),
                false => None,
            })
            .collect::<Vec<_>>()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::uncommon_from_sentences(
            "this apple is sweet".to_string(),
            "this apple is sour".to_string()
        ),
        vec!["sour".to_string(), "sweet".to_string()]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::uncommon_from_sentences("apple apple".to_string(), "banana".to_string()),
        vec!["banana".to_string()]
    );
}
