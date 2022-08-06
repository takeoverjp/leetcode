/*
 * @lc app=leetcode id=821 lang=rust
 *
 * [821] Shortest Distance to a Character
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
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let len = s.len();
        let s = s.chars().collect::<Vec<char>>();
        let mut ret = Vec::<i32>::new();
        ret.resize(len, 0);
        let mut indices = vec![];
        for i in 0..len {
            if s[i] == c {
                indices.push(i);
            }
        }
        for i in 0..len {
            let mut distance = i32::MAX;
            for index in &indices {
                distance = distance.min(i32::abs(*index as i32 - i as i32));
            }
            ret[i] = distance;
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::shortest_to_char("loveleetcode".to_string(), 'e'),
        vec![3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::shortest_to_char("aaab".to_string(), 'b'),
        vec![3, 2, 1, 0]
    );
}
