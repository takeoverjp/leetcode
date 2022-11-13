/*
 * @lc app=leetcode id=1436 lang=rust
 *
 * [1436] Destination City
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
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let mut starting_cities = std::collections::HashSet::<String>::new();
        for e in &paths {
            starting_cities.insert(e[0].clone());
        }
        for e in paths {
            if !starting_cities.contains(&e[1]) {
                return e[1].clone();
            }
        }
        "".to_string()
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::dest_city(vec![
            vec!["London".to_string(), "New York".to_string()],
            vec!["New York".to_string(), "Lima".to_string()],
            vec!["Lima".to_string(), "Sao Paulo".to_string()]
        ]),
        "Sao Paulo".to_string()
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::dest_city(vec![
            vec!["B".to_string(), "C".to_string()],
            vec!["D".to_string(), "B".to_string()],
            vec!["C".to_string(), "A".to_string()]
        ],),
        "A".to_string()
    );
}

#[test]
fn test3() {
    assert_eq!(
        Solution::dest_city(vec![vec!["A".to_string(), "Z".to_string()]]),
        "Z".to_string()
    );
}
