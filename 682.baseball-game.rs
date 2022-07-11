/*
 * @lc app=leetcode id=682 lang=rust
 *
 * [682] Baseball Game
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
    pub fn cal_points(ops: Vec<String>) -> i32 {
        let mut work = Vec::<i32>::new();
        work.resize(ops.len(), 0);
        let mut last_idx = 0;
        for op in ops {
            match op.as_str() {
                "C" => {
                    work[last_idx - 1] = 0;
                    last_idx -= 1;
                }
                "D" => {
                    work[last_idx] = work[last_idx - 1] * 2;
                    last_idx += 1;
                }
                "+" => {
                    work[last_idx] = work[last_idx - 1] + work[last_idx - 2];
                    last_idx += 1;
                }
                _ => {
                    work[last_idx] = op.parse::<i32>().unwrap();
                    last_idx += 1;
                }
            }
        }
        work.iter().sum()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::cal_points(vec![
            "5".to_string(),
            "2".to_string(),
            "C".to_string(),
            "D".to_string(),
            "+".to_string()
        ]),
        30
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::cal_points(vec![
            "5".to_string(),
            "-2".to_string(),
            "4".to_string(),
            "C".to_string(),
            "D".to_string(),
            "9".to_string(),
            "+".to_string(),
            "+".to_string()
        ]),
        27
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::cal_points(vec!["1".to_string(), "C".to_string()]),
        0
    );
}
