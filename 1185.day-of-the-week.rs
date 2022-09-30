/*
 * @lc app=leetcode id=1185 lang=rust
 *
 * [1185] Day of the Week
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
    pub fn day_of_the_week(d: i32, mut m: i32, mut y: i32) -> String {
        let days = [
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday",
            "Friday",
            "Saturday",
        ];
        if m < 3 {
            m += 12;
            y -= 1;
        }
        let c = y / 100;
        y %= 100;
        let w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        days[((w + 7) % 7) as usize].to_string()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::day_of_the_week(31, 8, 2019),
        "Saturday".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::day_of_the_week(18, 7, 1999), "Sunday".to_string());
}

#[test]
fn test3() {
    assert_eq!(Solution::day_of_the_week(15, 8, 1993), "Sunday".to_string());
}
