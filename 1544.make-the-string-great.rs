/*
 * @lc app=leetcode id=1544 lang=rust
 *
 * [1544] Make The String Great
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
    pub fn make_good(s: String) -> String {
        let s = s.chars().collect::<Vec<char>>();
        let mut ans = vec![];
        let mut i = 0;
        while i < s.len() {
            ans.push(s[i]);
            while !ans.is_empty()
                && i < s.len() - 1
                && (ans[ans.len() - 1] as u8 == s[i + 1] as u8 + 32
                    || ans[ans.len() - 1] as u8 == s[i + 1] as u8 - 32)
            {
                ans.pop();
                i += 1;
            }
            i += 1;
        }
        ans.iter().collect::<String>()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::make_good("leEeetcode".to_string()),
        "leetcode".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::make_good("abBAcC".to_string()), "".to_string());
}

#[test]
fn test3() {
    assert_eq!(Solution::make_good("s".to_string()), "s".to_string());
}
