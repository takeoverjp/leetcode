/*
 * @lc app=leetcode id=1221 lang=rust
 *
 * [1221] Split a String in Balanced Strings
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
    pub fn balanced_string_split(s: String) -> i32 {
        let mut ret = 0;
        let mut cnt = 0;
        for c in s.chars() {
            if c == 'L' {
                cnt += 1;
            } else {
                cnt -= 1;
            }
            if cnt == 0 {
                ret += 1;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::balanced_string_split("RLRRLLRLRL".to_string()), 4);
}

#[test]
fn test2() {
    assert_eq!(Solution::balanced_string_split("RLRRRLLRLL".to_string()), 2);
}

#[test]
fn test3() {
    assert_eq!(Solution::balanced_string_split("LLLLRRRR".to_string()), 1);
}
