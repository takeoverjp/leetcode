/*
 * @lc app=leetcode id=242 lang=rust
 *
 * [242] Valid Anagram
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
impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut count_s: [i32; 26] = [0; 26];
        let mut count_t: [i32; 26] = [0; 26];
        for c in s.chars() {
            let idx: usize = (c as u8 - 'a' as u8) as usize;
            count_s[idx] += 1;
        }
        for c in t.chars() {
            let idx: usize = (c as u8 - 'a' as u8) as usize;
            count_t[idx] += 1;
        }
        count_s == count_t
    }
}
// @lc code=end

#[test]
fn test1() {
    assert!(Solution::is_anagram(
        "anagram".to_string(),
        "nagaram".to_string()
    ));
}

#[test]
fn test2() {
    assert!(!Solution::is_anagram("ret".to_string(), "car".to_string()));
}
