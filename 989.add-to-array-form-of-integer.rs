/*
 * @lc app=leetcode id=989 lang=rust
 *
 * [989] Add to Array-Form of Integer
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
    pub fn add_to_array_form(num: Vec<i32>, mut k: i32) -> Vec<i32> {
        let size = num.len();
        let mut k_size = 0;
        let mut tmp = k;
        while tmp > 0 {
            tmp /= 10;
            k_size += 1;
        }
        let max_size = size.max(k_size) + 1;
        let mut ret = Vec::<i32>::new();
        ret.resize(max_size, 0);
        let mut i = 0;
        while i < size || k > 0 {
            let lhs = if i < size { num[size - i - 1] } else { 0 };
            let rhs = k % 10;
            ret[max_size - i - 1] += lhs + rhs;
            if ret[max_size - i - 1] >= 10 {
                ret[max_size - i - 1] -= 10;
                ret[max_size - i - 2] += 1;
            }
            k /= 10;
            i += 1;
        }
        if ret[0] == 0 {
            ret.remove(0);
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::add_to_array_form(vec![1, 2, 0, 0], 34),
        vec![1, 2, 3, 4]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::add_to_array_form(vec![2, 7, 4], 181),
        vec![4, 5, 5]
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::add_to_array_form(vec![2, 1, 5], 806),
        vec![1, 0, 2, 1]
    );
}
