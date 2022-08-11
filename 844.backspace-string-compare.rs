/*
 * @lc app=leetcode id=844 lang=rust
 *
 * [844] Backspace String Compare
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
    pub fn backspace_compare(s: String, t: String) -> bool {
        let mut s_i = s.chars().rev();
        let mut t_i = t.chars().rev();

        loop {
            let s_char = Self::get_next(&mut s_i);
            let t_char = Self::get_next(&mut t_i);
            if s_char == None && t_char == None {
                break true;
            }
            if s_char != t_char {
                break false;
            }
        }
    }

    fn get_next(iter: &mut impl Iterator<Item = char>) -> Option<char> {
        let mut skip = 0;
        loop {
            let cur = iter.next();
            match cur {
                Some('#') => skip += 1,
                None => break None,
                Some(x) => {
                    if skip == 0 {
                        break Some(x);
                    }
                    skip -= 1;
                }
            }
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::backspace_compare(
        "ab#c".to_string(),
        "ad#c".to_string()
    ));
}

#[test]
fn test2() {
    assert!(Solution::backspace_compare(
        "ab##".to_string(),
        "c#d#".to_string()
    ));
}

#[test]
fn test3() {
    assert!(!Solution::backspace_compare(
        "a#c".to_string(),
        "b".to_string()
    ));
}
