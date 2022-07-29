/*
 * @lc app=leetcode id=762 lang=rust
 *
 * [762] Prime Number of Set Bits in Binary Representation
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
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        let mut count = 0;
        for i in left..=right {
            if Solution::is_prime(i.count_ones() as i32) {
                count += 1;
            }
        }
        count
    }

    fn is_prime(n: i32) -> bool {
        if n <= 1 {
            return false;
        }
        let sqrtn: i32 = (n as f32).sqrt() as i32;
        for i in 2..=sqrtn {
            if n % i == 0 {
                return false;
            }
        }
        true
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::count_prime_set_bits(6, 10), 4);
}

#[test]
fn test2() {
    assert_eq!(Solution::count_prime_set_bits(10, 15), 5);
}
