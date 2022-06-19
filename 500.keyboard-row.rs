/*
 * @lc app=leetcode id=500 lang=rust
 *
 * [500] Keyboard Row
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
    fn is_keyboard_row(word: &str) -> bool {
        let rows = vec![
            "qwertyuiopQWERTYUIOP".to_string(),
            "asdfghjklASDFGHJKL".to_string(),
            "zxcvbnmZXCVBNM".to_string(),
        ];
        for row in rows {
            let mut is_match = true;
            for c in word.chars() {
                if row.find(c) == None {
                    is_match = false;
                    break;
                }
            }
            if is_match {
                return true;
            }
        }
        false
    }
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        let mut ret = Vec::<String>::new();
        for word in words {
            if Solution::is_keyboard_row(&word) {
                ret.push(word);
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_words(vec![
            "Hello".to_string(),
            "Alaska".to_string(),
            "Dad".to_string(),
            "Peace".to_string()
        ]),
        vec!["Alaska".to_string(), "Dad".to_string()]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_words(vec!["omk".to_string()]),
        Vec::<String>::new()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::find_words(vec!["adsdf".to_string(), "sfd".to_string()]),
        vec!["adsdf".to_string(), "sfd".to_string()]
    );
}

#[test]
fn test4() {
    assert_eq!(
        Solution::find_words(vec!["qwee".to_string()]),
        vec!["qwee".to_string()]
    );
}
