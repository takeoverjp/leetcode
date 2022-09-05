/*
 * @lc app=leetcode id=1002 lang=rust
 *
 * [1002] Find Common Characters
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

macro_rules! vec_of_strings {
    ($($x:expr),*) => (vec![$($x.to_string()),*]);
}

// @lc code=start
impl Solution {
    pub fn common_chars(words: Vec<String>) -> Vec<String> {
        let mut cnt = [i32::MAX; 26];
        let mut ret = Vec::<String>::new();
        for s in words {
            let mut cnt1 = [0; 26];
            for c in s.bytes() {
                cnt1[(c as u8 - b'a') as usize] += 1;
            }
            for i in 0..26 {
                cnt[i] = cnt[i].min(cnt1[i]);
            }
        }
        for (i, c) in cnt.iter().enumerate() {
            for _j in 0..*c {
                ret.push(((i as u8 + b'a') as char).to_string())
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::common_chars(vec_of_strings!["bella", "label", "roller"]),
        vec_of_strings!["e", "l", "l"]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::common_chars(vec_of_strings!["cool", "lock", "cook"]),
        vec_of_strings!["c", "o"]
    );
}
