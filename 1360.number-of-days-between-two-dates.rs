/*
 * @lc app=leetcode id=1360 lang=rust
 *
 * [1360] Number of Days Between Two Dates
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
    pub fn days_between_dates(date1: String, date2: String) -> i32 {
        (Solution::date_to_int(date2) - Solution::date_to_int(date1)).abs()
    }

    fn date_to_int(date: String) -> i32 {
        let y = date[0..4].parse::<i32>().unwrap();
        let m = date[5..7].parse::<i32>().unwrap();
        let d = date[8..10].parse::<i32>().unwrap();
        let mut date = 0;
        for yi in 1971..y {
            date += if Solution::is_leap_year(yi) { 366 } else { 365 };
        }
        for mi in 1..m {
            date += Solution::days_in_month(mi, y);
        }
        date + d
    }

    fn is_leap_year(year: i32) -> bool {
        (year % 4 == 0 && year % 100 != 0) || year % 400 == 0
    }

    fn days_in_month(m: i32, year: i32) -> i32 {
        if m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 {
            return 31;
        }
        if m == 2 {
            return if Solution::is_leap_year(year) { 29 } else { 28 };
        }
        30
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::days_between_dates("2019-06-29".to_string(), "2019-06-30".to_string()),
        1
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::days_between_dates("2020-01-15".to_string(), "2019-12-31".to_string()),
        15
    );
}
