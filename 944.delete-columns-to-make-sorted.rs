/*
 * @lc app=leetcode id=944 lang=rust
 *
 * [944] Delete Columns to Make Sorted
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
    pub fn min_deletion_size(strs: Vec<String>) -> i32 {
        let mut ret = 0;
        let row_num = strs.len();
        let column_num = strs[0].len();
        for x in 0..column_num {
            for y in 1..row_num {
                if strs[y].chars().nth(x).unwrap() < strs[y - 1].chars().nth(x).unwrap() {
                    ret += 1;
                    break;
                }
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::min_deletion_size(vec![
            "cba".to_string(),
            "daf".to_string(),
            "ghi".to_string()
        ]),
        1
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::min_deletion_size(vec!["a".to_string(), "b".to_string()]),
        0
    );
    assert_eq!(
        Solution::min_deletion_size(vec![
            "zyx".to_string(),
            "wvu".to_string(),
            "tsr".to_string()
        ]),
        3
    );
}
