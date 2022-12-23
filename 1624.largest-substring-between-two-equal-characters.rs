/*
 * @lc app=leetcode id=1624 lang=rust
 *
 * [1624] Largest Substring Between Two Equal Characters
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
    pub fn max_length_between_equal_characters(s: String) -> i32 {
        let mut ans: i32 = -1;
        let mut mp = std::collections::HashMap::<char, i32>::new();
        if s.len() == 1 {
            return -1;
        }

        let s = s.chars().collect::<Vec<char>>();
        for i in 0..s.len() {
            if mp.contains_key(&s[i]) {
                ans = ans.max(i as i32 - mp[&s[i]] - 1);
            } else {
                *mp.entry(s[i]).or_insert(0) = i as i32;
            }
        }
        ans
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::max_length_between_equal_characters("aa".to_string()),
        0
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::max_length_between_equal_characters("abca".to_string()),
        2
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::max_length_between_equal_characters("cbzxy".to_string()),
        -1
    );
}
