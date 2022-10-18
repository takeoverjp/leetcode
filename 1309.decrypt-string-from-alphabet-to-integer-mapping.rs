/*
 * @lc app=leetcode id=1309 lang=rust
 *
 * [1309] Decrypt String from Alphabet to Integer Mapping
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
    pub fn freq_alphabets(s: String) -> String {
        let n = s.len();
        let mut i = 0;
        let mut ans = String::new();
        while i < n {
            if i + 2 < n && s.as_bytes()[(i + 2) as usize] == b'#' {
                let ss = (s.as_bytes()[i as usize] - b'0') * 10
                    + (s.as_bytes()[(i + 1) as usize] - b'0');
                ans += &((ss + b'a' - 1) as char).to_string();
                i += 3;
            } else {
                ans += &((s.as_bytes()[i as usize] - b'0' - 1 + b'a') as char).to_string();
                i += 1;
            }
        }
        ans
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::freq_alphabets("10#11#12".to_string()),
        "jkab".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::freq_alphabets("1326#".to_string()),
        "acz".to_string()
    );
}
