/*
 * @lc app=leetcode id=1979 lang=rust
 *
 * [1979] Find Greatest Common Divisor of Array
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

#[macro_export]
macro_rules! list_node {
    ( $x:expr,$( $y:expr ),* ) => {
        {
            let mut head = Some(Box::new(ListNode::new($x)));
            let mut tail = &mut head;
            $(
                let mut node = Some(Box::new(ListNode::new($y)));
                tail.as_mut().unwrap().next = node;
                tail = &mut tail.as_mut().unwrap().next;
            )*
            head
        }
    };
}

// @lc code=start
impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let mut min_num = i32::MAX;
        let mut max_num = i32::MIN;
        for num in nums {
            min_num = std::cmp::min(min_num, num);
            max_num = std::cmp::max(max_num, num);
        }
        while max_num - min_num > 1 {
            let diff = max_num - min_num;
            max_num = std::cmp::max(diff, min_num);
            min_num = std::cmp::min(diff, min_num);
        }
        if max_num == min_num {
            max_num
        } else {
            1
        }
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_gcd(vec![2, 5, 6, 9, 10]), 2);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_gcd(vec![7, 5, 6, 8, 3]), 1);
}

#[test]
fn test3() {
    assert_eq!(Solution::find_gcd(vec![3, 3]), 3);
}
