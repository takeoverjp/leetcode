/*
 * @lc app=leetcode id=1636 lang=rust
 *
 * [1636] Sort Array by Increasing Frequency
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
    pub fn frequency_sort(mut nums: Vec<i32>) -> Vec<i32> {
        let mut cnt = [0; 201];
        for n in &nums {
            cnt[(*n + 100) as usize] += 1;
        }
        nums.sort_by(|a: &i32, b: &i32| {
            if cnt[(*a + 100) as usize] == cnt[(*b + 100) as usize] {
                b.cmp(a)
            } else {
                cnt[(*a + 100) as usize].cmp(&cnt[(*b + 100) as usize])
            }
        });
        nums
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::frequency_sort(vec![1, 1, 2, 2, 2, 3]),
        vec![3, 1, 1, 2, 2, 2]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::frequency_sort(vec![2, 3, 1, 3, 2]),
        vec![1, 3, 3, 2, 2]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::frequency_sort(vec![-1, 1, -6, 4, 5, -6, 1, 4, 1]),
        vec![5, -1, 4, 4, -6, -6, 1, 1, 1]
    );
}
