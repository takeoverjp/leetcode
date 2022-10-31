/*
 * @lc app=leetcode id=1370 lang=rust
 *
 * [1370] Increasing Decreasing String
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
    pub fn sort_string(s: String) -> String {
        let mut cnt = [0; 26];
        for c in s.bytes() {
            cnt[(c - b'a') as usize] += 1;
        }
        let mut ret = "".to_string();
        while s.len() != ret.len() {
            for i in 0..26 {
                cnt[i] -= 1;
                if cnt[i] >= 0 {
                    ret += &((b'a' + i as u8) as char).to_string();
                }
            }
            for i in (0..26).rev() {
                cnt[i] -= 1;
                if cnt[i] >= 0 {
                    ret += &((b'a' + i as u8) as char).to_string();
                }
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::sort_string("aaaabbbbcccc".to_string()),
        "abccbaabccba".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::sort_string("rat".to_string()), "art".to_string());
}
