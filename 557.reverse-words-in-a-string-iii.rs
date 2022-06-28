/*
 * @lc app=leetcode id=557 lang=rust
 *
 * [557] Reverse Words in a String III
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
    pub fn reverse_words(s: String) -> String {
        let len = s.len();
        let s = s.chars().collect::<Vec<char>>();
        let mut ret = s.clone();
        let mut start = 0;
        while start < len {
            let mut end = start;
            eprintln!("start = {}, len = {}", start, len);
            for i in start..=len {
                if i == len {
                    end = len;
                    break;
                }
                if s[i] == ' ' {
                    end = i;
                    break;
                }
            }

            for i in start..end {
                ret[i] = s[(end - 1) - (i - start)];
            }

            start = end + 1;
        }

        ret.iter().collect()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reverse_words("Let's take LeetCode contest".to_string()),
        "s'teL ekat edoCteeL tsetnoc".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reverse_words("God Ding".to_string()),
        "doG gniD".to_string()
    );
}
