/*
 * @lc app=leetcode id=401 lang=rust
 *
 * [401] Binary Watch
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
    pub fn read_binary_watch(turned_on: i32) -> Vec<String> {
        let mut ret = Vec::<String>::new();
        for h in 0..12i32 {
            let bit_h = h.count_ones();
            for m in 0..60i32 {
                let bit_m = m.count_ones();
                if bit_h + bit_m == turned_on as u32 {
                    ret.push(format!("{}:{:02}", h, m));
                }
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::read_binary_watch(1),
        vec![
            "0:01".to_string(),
            "0:02".to_string(),
            "0:04".to_string(),
            "0:08".to_string(),
            "0:16".to_string(),
            "0:32".to_string(),
            "1:00".to_string(),
            "2:00".to_string(),
            "4:00".to_string(),
            "8:00".to_string()
        ]
    );
}

#[test]
fn test2() {
    assert_eq!(Solution::read_binary_watch(9), Vec::<String>::new());
}
