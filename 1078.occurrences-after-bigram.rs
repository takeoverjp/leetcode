/*
 * @lc app=leetcode id=1078 lang=rust
 *
 * [1078] Occurrences After Bigram
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
    pub fn find_ocurrences(text: String, first: String, second: String) -> Vec<String> {
        let mut ret = Vec::<String>::new();
        let mut prev2 = "".to_string();
        let mut prev = "".to_string();
        for word in text.split_ascii_whitespace() {
            if prev2 == first && prev == second {
                ret.push(word.to_string());
            }
            prev2 = prev;
            prev = word.to_string();
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_ocurrences(
            "alice is a good girl she is a good student".to_string(),
            "a".to_string(),
            "good".to_string()
        ),
        vec!["girl".to_string(), "student".to_string()]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_ocurrences(
            "we will we will rock you".to_string(),
            "we".to_string(),
            "will".to_string()
        ),
        vec!["we".to_string(), "rock".to_string()]
    );
}
