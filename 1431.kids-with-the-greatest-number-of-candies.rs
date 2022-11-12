/*
 * @lc app=leetcode id=1431 lang=rust
 *
 * [1431] Kids With the Greatest Number of Candies
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
    pub fn kids_with_candies(candies: Vec<i32>, extra_candies: i32) -> Vec<bool> {
        let mut ret = vec![];
        let mut max_candy = i32::MIN;
        for candy in &candies {
            max_candy = max_candy.max(*candy);
        }

        for candy in candies {
            if candy + extra_candies >= max_candy {
                ret.push(true);
            } else {
                ret.push(false);
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::kids_with_candies(vec![2, 3, 5, 1, 3], 3),
        vec![true, true, true, false, true]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::kids_with_candies(vec![4, 2, 1, 1, 2], 1),
        vec![true, false, false, false, false]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::kids_with_candies(vec![12, 1, 12], 10),
        vec![true, false, true]
    );
}
