/*
 * @lc app=leetcode id=506 lang=rust
 *
 * [506] Relative Ranks
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
    pub fn find_relative_ranks(score: Vec<i32>) -> Vec<String> {
        let len = score.len();

        let mut score_sort = score.clone();
        score_sort.sort_unstable();

        let gold = score_sort.pop().unwrap_or(-1);
        let silver = score_sort.pop().unwrap_or(-1);
        let bronze = score_sort.pop().unwrap_or(-1);

        score
            .iter()
            .map(|&x| match x {
                _ if x == gold => "Gold Medal".to_string(),
                _ if x == silver => "Silver Medal".to_string(),
                _ if x == bronze => "Bronze Medal".to_string(),
                _ => score_sort
                    .binary_search(&x)
                    .map_or(0, |i| len - i)
                    .to_string(),
            })
            .collect()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_relative_ranks(vec![5, 4, 3, 2, 1]),
        vec![
            "Gold Medal".to_string(),
            "Silver Medal".to_string(),
            "Bronze Medal".to_string(),
            "4".to_string(),
            "5".to_string()
        ]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_relative_ranks(vec![10, 3, 8, 9, 4]),
        vec![
            "Gold Medal".to_string(),
            "5".to_string(),
            "Bronze Medal".to_string(),
            "Silver Medal".to_string(),
            "4".to_string()
        ]
    );
}
