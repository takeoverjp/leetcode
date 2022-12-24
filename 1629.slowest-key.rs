/*
 * @lc app=leetcode id=1629 lang=rust
 *
 * [1629] Slowest Key
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
    pub fn slowest_key(release_times: Vec<i32>, keys_pressed: String) -> char {
        let mut vect = vec![];
        let mut mp = std::collections::HashMap::<char, i32>::new();
        let keys_pressed = keys_pressed.chars().collect::<Vec<char>>();
        *mp.entry(keys_pressed[0]).or_insert(0) = release_times[0];
        let mut curr_max = release_times[0];
        for i in 1..keys_pressed.len() {
            let diff = release_times[i] - release_times[i - 1];
            let entry = mp.entry(keys_pressed[i]).or_insert(diff);
            *entry = (*entry).max(diff);
            curr_max = curr_max.max(release_times[i] - release_times[i - 1]);
        }
        for (c, i) in mp {
            if i == curr_max {
                vect.push(c);
            }
        }
        vect.sort_unstable();
        vect[vect.len() - 1]
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::slowest_key(vec![9, 29, 49, 50], "cbcd".to_string()),
        'c'
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::slowest_key(vec![12, 23, 36, 46, 62], "spuda".to_string()),
        'a'
    );
}
