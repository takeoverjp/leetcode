/*
 * @lc app=leetcode id=917 lang=rust
 *
 * [917] Reverse Only Letters
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
    pub fn reverse_only_letters(s: String) -> String {
        let mut sb = s.into_bytes();
        let (mut i, mut j) = (0, sb.len() - 1);
        while i < j {
            if !sb[i].is_ascii_alphabetic() {
                i += 1;
            } else if !sb[j].is_ascii_alphabetic() {
                j -= 1;
            } else {
                sb.swap(i, j);
                i += 1;
                j -= 1;
            }
        }
        String::from_utf8(sb).unwrap()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reverse_only_letters("ab-cd".to_string()),
        "dc-ba".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::reverse_only_letters("a-bC-dEf-ghIj".to_string()),
        "j-Ih-gfE-dCba".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::reverse_only_letters("Test1ng-Leet=code-Q!".to_string()),
        "Qedo1ct-eeLg=ntse-T!".to_string()
    );
}
