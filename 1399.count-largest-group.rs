/*
 * @lc app=leetcode id=1399 lang=rust
 *
 * [1399] Count Largest Group
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
    pub fn count_largest_group(n: i32) -> i32 {
        let mut cnt = [0; 37];
        let mut mx = 0;
        for i in 1..=n {
            let d = Solution::dsum(i) as usize;
            cnt[d] += 1;
            mx = mx.max(cnt[d]);
        }
        cnt.iter().filter(|&a| *a == mx).count() as i32
    }

    fn dsum(n: i32) -> i32 {
        if n == 0 {
            0
        } else {
            n % 10 + Solution::dsum(n / 10)
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::count_largest_group(13), 4);
}

#[test]
fn test2() {
    assert_eq!(Solution::count_largest_group(2), 2);
}
