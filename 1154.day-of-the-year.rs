/*
 * @lc app=leetcode id=1154 lang=rust
 *
 * [1154] Day of the Year
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
    pub fn day_of_year(date: String) -> i32 {
        let days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        let y = date[0..4].to_string().parse::<i32>().unwrap();
        let mut m = date[5..7].to_string().parse::<i32>().unwrap();
        let mut d = date[8..10].to_string().parse::<i32>().unwrap();
        if m > 2 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0) {
            d += 1;
        }
        while m > 1 {
            m -= 1;
            d += days[(m - 1) as usize];
        }
        d
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::day_of_year("2019-01-09".to_string()), 9);
}

#[test]
fn test2() {
    assert_eq!(Solution::day_of_year("2019-02-10".to_string()), 41);
}
