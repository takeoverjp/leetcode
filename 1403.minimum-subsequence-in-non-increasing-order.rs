/*
 * @lc app=leetcode id=1403 lang=rust
 *
 * [1403] Minimum Subsequence in Non-Increasing Order
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
    pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {
        let mut sum = 0;
        let mut newsum = 0;
        let mut ans = vec![];
        for num in &nums {
            sum += num;
        }
        nums.sort_by(|a, b| b.cmp(a));

        for num in nums {
            newsum += num;
            sum -= num;
            ans.push(num);
            if newsum > sum {
                break;
            }
        }
        ans.sort_by(|a, b| b.cmp(a));
        ans
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::min_subsequence(vec![4, 3, 10, 9, 8]), vec![10, 9]);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::min_subsequence(vec![4, 4, 7, 6, 7]),
        vec![7, 7, 6]
    );
}
