/*
 * @lc app=leetcode id=1071 lang=rust
 *
 * [1071] Greatest Common Divisor of Strings
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
fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}
impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        let cstr1 = str1.clone();
        let cstr2 = str2.clone();
        if cstr1 + &str2 == cstr2 + &str1 {
            str1[..gcd(str1.len(), str2.len())].to_string()
        } else {
            "".to_string()
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::gcd_of_strings("ABCABC".to_string(), "ABC".to_string()),
        "ABC".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::gcd_of_strings("ABABAB".to_string(), "ABAB".to_string()),
        "AB".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::gcd_of_strings("LEET".to_string(), "CODE".to_string()),
        "".to_string()
    );
}
