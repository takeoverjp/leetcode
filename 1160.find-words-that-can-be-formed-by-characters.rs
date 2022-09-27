/*
 * @lc app=leetcode id=1160 lang=rust
 *
 * [1160] Find Words That Can Be Formed by Characters
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
    pub fn count_characters(words: Vec<String>, chars: String) -> i32 {
        let mut cnt = [0; 26];
        let mut ret: i32 = 0;
        for c in chars.chars() {
            let index = c as usize - 'a' as usize;
            cnt[index] += 1;
        }
        for w in words {
            let mut cnt1 = [0; 26];
            let mut is_match = true;
            for c in w.chars() {
                let index = c as usize - 'a' as usize;
                cnt1[index] += 1;
                if cnt1[index] > cnt[index] {
                    is_match = false;
                    break;
                }
            }
            if is_match {
                ret += w.len() as i32;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::count_characters(
            vec![
                "cat".to_string(),
                "bt".to_string(),
                "hat".to_string(),
                "tree".to_string()
            ],
            "atach".to_string()
        ),
        6
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::count_characters(
            vec![
                "hello".to_string(),
                "world".to_string(),
                "leetcode".to_string()
            ],
            "welldoneheneyr".to_string()
        ),
        10
    );
}
