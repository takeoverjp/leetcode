/*
 * @lc app=leetcode id=599 lang=rust
 *
 * [599] Minimum Index Sum of Two Lists
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
    pub fn find_restaurant(list1: Vec<String>, list2: Vec<String>) -> Vec<String> {
        let mut ret = vec![];
        let len1 = list1.len();
        let len2 = list2.len();
        for idx_sum in 0..(len1 + len2) {
            for (idx2, item2) in list2.iter().enumerate() {
                if idx2 > idx_sum {
                    break;
                }
                let idx1 = idx_sum - idx2;
                if idx1 >= len1 {
                    continue;
                }
                if list1[idx1] == *item2 {
                    ret.push(list1[idx1].clone());
                }
            }
            if !ret.is_empty() {
                return ret;
            }
        }
        ret
    }
}
// @lc code=end

#[test]
fn test1() {
    assert_eq!(
        Solution::find_restaurant(
            vec![
                "Shogun".to_string(),
                "Tapioca Express".to_string(),
                "Burger King".to_string(),
                "KFC".to_string()
            ],
            vec![
                "Piatti".to_string(),
                "The Grill at Torrey Pines".to_string(),
                "Hungry Hunter Steakhouse".to_string(),
                "Shogun".to_string()
            ]
        ),
        vec!["Shogun".to_string()]
    );
}

#[test]
fn test2() {
    assert_eq!(
        Solution::find_restaurant(
            vec![
                "Shogun".to_string(),
                "Tapioca Express".to_string(),
                "Burger King".to_string(),
                "KFC".to_string()
            ],
            vec![
                "KFC".to_string(),
                "Shogun".to_string(),
                "Burger King".to_string()
            ]
        ),
        vec!["Shogun".to_string()]
    );
}
