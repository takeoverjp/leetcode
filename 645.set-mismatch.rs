/*
 * @lc app=leetcode id=645 lang=rust
 *
 * [645] Set Mismatch
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
    pub fn find_error_nums(mut nums: Vec<i32>) -> Vec<i32> {
        let mut ret = Vec::<i32>::new();
        let size = nums.len();
        for i in 0..size {
            let num = nums[i].abs() as usize;
            if nums[num - 1] < 0 {
                ret.push(nums[i].abs());
            } else {
                nums[num - 1] *= -1;
            }
        }
        for i in 0..size {
            if nums[i] > 0 {
                ret.push(i as i32 + 1);
                break;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::find_error_nums(vec![1, 2, 2, 4]), vec![2, 3]);
}

#[test]
fn test2() {
    assert_eq!(Solution::find_error_nums(vec![1, 1]), vec![1, 2]);
}
