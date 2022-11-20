/*
 * @lc app=leetcode id=1455 lang=rust
 *
 * [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
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
    pub fn is_prefix_of_word(sentence: String, search_word: String) -> i32 {
        let mut c = 1;
        let n = sentence.len();
        let mut i = 0;
        let mut b = false;
        let mut t = "".to_string();
        let sentence = sentence.chars().collect::<Vec<char>>();
        while i < n {
            if sentence[i] != ' ' {
                t += &sentence[i].to_string();
                if t == search_word {
                    b = true;
                    break;
                }
            } else {
                c += 1;
                t = "".to_string();
            }
            i += 1;
        }
        if b {
            c
        } else {
            -1
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::is_prefix_of_word("i love eating burger".to_string(), "burg".to_string()),
        4
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::is_prefix_of_word(
            "this problem is an easy problem".to_string(),
            "pro".to_string()
        ),
        2
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::is_prefix_of_word("i am tired".to_string(), "searchWord".to_string()),
        -1
    );
}
