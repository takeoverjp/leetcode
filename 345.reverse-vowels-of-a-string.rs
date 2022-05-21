/*
 * @lc app=leetcode id=345 lang=rust
 *
 * [345] Reverse Vowels of a String
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
    pub fn reverse_vowels(s: String) -> String {
        let is_vowel = |c| matches!(c, 'a' | 'e' | 'i' | 'o' | 'u' | 'A' | 'E' | 'I' | 'O' | 'U');
        let mut char_vec = s.chars().collect::<Vec<char>>();
        let mut first = 0;
        let mut last = s.len() - 1;
        while first < last {
            let mut is_first_found = false;
            let mut is_last_found = false;
            for (i, c) in char_vec.iter().enumerate().take(last + 1).skip(first) {
                if is_vowel(*c) {
                    first = i;
                    is_first_found = true;
                    break;
                }
            }
            for (i, c) in char_vec.iter().enumerate().take(last + 1).skip(first).rev() {
                if is_vowel(*c) {
                    last = i;
                    is_last_found = true;
                    break;
                }
            }
            if !is_first_found || !is_last_found || (first == last) {
                break;
            }
            char_vec.swap(first, last);

            first += 1;
            last -= 1;
        }
        char_vec.into_iter().collect()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reverse_vowels("hello".to_string()),
        "holle".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reverse_vowels("leetcode".to_string()),
        "leotcede".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::reverse_vowels("a.".to_string()), "a.".to_string());
}

#[test]
fn test4() {
    assert_eq!(Solution::reverse_vowels("aA".to_string()), "Aa".to_string());
}
