/*
 * @lc app=leetcode id=1684 lang=rust
 *
 * [1684] Count the Number of Consistent Strings
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
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mut arr = vec![0; 26];
        let mut res = 0;
        for ch in allowed.chars() {
            arr[(ch as u8 - b'a') as usize] = 1;
        }
        for w in words {
            let mut flag = false;
            for ch in w.chars() {
                if arr[(ch as u8 - b'a') as usize] == 0 {
                    flag = true;
                    break;
                }
            }
            if flag {
                continue;
            } else {
                res += 1;
            }
        }
        res
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::count_consistent_strings(
            "ab".to_string(),
            vec![
                "ad".to_string(),
                "bd".to_string(),
                "aaab".to_string(),
                "baa".to_string(),
                "badab".to_string()
            ]
        ),
        2
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::count_consistent_strings(
            "abc".to_string(),
            vec![
                "a".to_string(),
                "b".to_string(),
                "c".to_string(),
                "ab".to_string(),
                "ac".to_string(),
                "bc".to_string(),
                "abc".to_string()
            ]
        ),
        7
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::count_consistent_strings(
            "cad".to_string(),
            vec![
                "cc".to_string(),
                "acd".to_string(),
                "b".to_string(),
                "ba".to_string(),
                "bac".to_string(),
                "bad".to_string(),
                "ac".to_string(),
                "d".to_string()
            ]
        ),
        4
    );
}
