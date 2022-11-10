/*
 * @lc app=leetcode id=1417 lang=rust
 *
 * [1417] Reformat The String
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
    pub fn reformat(s: String) -> String {
        let mut a = Vec::<char>::new();
        let mut d = Vec::<char>::new();
        let mut s = s.chars().collect::<Vec<char>>();
        for x in &s {
            if x.is_ascii_alphabetic() {
                a.push(*x);
            } else {
                d.push(*x);
            }
        }
        if (a.len() as i32 - d.len() as i32).abs() > 1 {
            return "".to_string();
        }
        let mut alpha = a.len() > d.len();
        let mut i = 0;
        let mut j = 0;
        let mut k = 0;
        while i < s.len() {
            if alpha {
                s[i] = a[j];
                i += 1;
                j += 1;
            } else {
                s[i] = d[k];
                i += 1;
                k += 1;
            }
            alpha = !alpha;
        }
        s.iter().collect::<String>()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::reformat("a0b1c2".to_string()),
        "0a1b2c".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::reformat("leetcode".to_string()), "".to_string());
}

#[test]
fn test3() {
    assert_eq!(Solution::reformat("1229857369".to_string()), "".to_string());
}
