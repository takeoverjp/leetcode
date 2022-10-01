/*
 * @lc app=leetcode id=1189 lang=rust
 *
 * [1189] Maximum Number of Balloons
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
    pub fn max_number_of_balloons(text: String) -> i32 {
        let mut mm = [0; 26];
        for i in text.chars() {
            mm[i as usize - 'a' as usize] += 1;
        }
        let a = 'a' as usize;
        mm[1]
            .min(mm[0])
            .min(mm['l' as usize - a] / 2)
            .min(mm['o' as usize - a] / 2)
            .min(mm['n' as usize - a])
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(Solution::max_number_of_balloons("nlaebolko".to_string()), 1);
}

#[test]
fn test2() {
    assert_eq!(
        Solution::max_number_of_balloons("loonbalxballpoon".to_string()),
        2
    );
}

#[test]
fn test3() {
    assert_eq!(Solution::max_number_of_balloons("leetcode".to_string()), 0);
}
