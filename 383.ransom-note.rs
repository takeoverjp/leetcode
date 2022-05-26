/*
 * @lc app=leetcode id=383 lang=rust
 *
 * [383] Ransom Note
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
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut magazine = magazine.chars().collect::<Vec<char>>();
        for c in ransom_note.chars() {
            match magazine.iter().find(|&&x| x == c) {
                Some(&mut x) => {
                    *x = 'X';
                }
                None => {
                    return false;
                }
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(!Solution::can_construct("a".to_string(), "b".to_string()));
}

#[test]
fn test2() {
    assert!(!Solution::can_construct("aa".to_string(), "ab".to_string()));
}

#[test]
fn test3() {
    assert!(Solution::can_construct("aa".to_string(), "aab".to_string()));
}
